#pragma once
/**
* @author �ž���
* @brief ���а�(��STL���)
***********************************************************************************************************
* @��hpp����C++�ӷ����������£�
* 1:constexpr
* 2:using����                                 ��û��usingָʾ����
* 3:����ָ��                                   shared_ptr
* 4:��������                                   function object��key_value_less��
* 5:��������                                   key_value_less������()�����
* 6:explicit                                   LeaderBoard���ι����ֹ��ʽת��
* 7:ģ����                                     ����key�Ȱ󶨽�ɫ���ƣ����ڼƻ����˺�
* 8:noexcept                                   �ƶ����캯��ָ�����׳��쳣
* 9:�ƶ����졢�ƶ���ֵ�����                   �Ż����ܣ�����delete�˿�����
* 10:��ֵ����                                  �����ƶ�����
* 11:���������                                �Ӵ�С����
* 12:STL������map��set����                     ������͹�ϣ����
* 13:�����ƶ�auto
* 14:lambda���ʽ                              ��������������
* 15:��ʼ���б�
* 16:STL��emplace����                          ���������ݸ����캯����emplaceʹ����Щ����������������ڴ�ռ���ֱ�ӹ���Ԫ��
*
* �ӿ�:insert_sum �����а񣬿�����������ȫ�ֱ�������һ��ȫ�ֱ�����cpp����h�ļ�����Ѱ˼�Ͼ��������Ҫ�����������������й��̵�
* ���Ի���������ཨ��һ��ȫ�ֶ�����Ϊ�����а�ʹ��insert_sum���������Ӧ������
* 
* �ӿ�:insert ������Ϸ�����а񣬻�������ഴ���Ķ�����ʹ��insert��������
* 
* �����ʣ�Ϊʲô�������ڳ�Ա����+
*/
#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>

template <class Key, class T>
class LeaderBoard {
public:
    using key_type = Key;
    using value_type = T;
    using size_type = std::size_t;

    // default: care of top 1000
    static constexpr size_type default_top = 1000;

    struct key_value_type
    {
        key_type first;
        value_type second;
        key_value_type(const key_type& k, const value_type& v) : first(k), second(v) {}
    };

    using key_value_ptr = std::shared_ptr<key_value_type>;

    struct key_value_less
    {
        constexpr bool operator()(const key_value_ptr& left,
            const key_value_ptr& right) const {
            if (left->second == right->second) 
            {
                return left->first < right->first;
            }
            return left->second < right->second;
        }
    };

    LeaderBoard() : _top(default_top) {}
    explicit LeaderBoard(size_type top) : _top(top == 0 ? default_top : top) {}
    LeaderBoard(const LeaderBoard&) = delete;
    LeaderBoard& operator=(const LeaderBoard&) = delete;
    ~LeaderBoard() = default;

    LeaderBoard(LeaderBoard&& right) noexcept
    {
        _top = right._top;
        _map = std::move(right._map);
        _set = std::move(right._set);
        return *this;
    }

    LeaderBoard& operator=(LeaderBoard&& right) noexcept
    {
        _top = right._top;
        _map = std::move(right._map);
        _set = std::move(right._set);
        return *this;
    }

    // ranged-for: large->small
    auto begin() const { return _set.rbegin(); }
    auto end() const { return _set.rend(); }

    auto find(key_type k) { return _map.find(k); }
    auto _mapend() { return _map.end(); }
    auto _setend() { return _set.end(); }


    //�ܰ�
    void insert_sum(const key_type& k, const value_type& v)
    {
        auto add = [&] {
            key_value_ptr ptr = std::make_shared<key_value_type>(k, v);
            _map.emplace(k, ptr);
            _set.insert(ptr);
        };

        auto it = _map.find(k);
        if (it == _map.end())
        {
            if (_set.size() < _top)
            {
                add();
            }
            else if (_set.size() == _top)
            {
                auto val = v;
                if (val < (*_set.begin())->second)
                    return;

                _map.erase((*_set.begin())->first);
                _set.erase(_set.begin());
                add();
            }
        }
        else
        {
            //��ͬ����һ��insert
            value_type tmp_value = ((*it).second)->second;
            value_type res_value = v + tmp_value;

            _set.erase(it->second);
            _map.erase(it);

            _map.emplace(k, std::make_shared<key_value_type>(k, res_value));
            _set.insert(std::make_shared<key_value_type>(k, res_value));
        }
    }

    //һ����Ϸ�İ�
    void insert(const key_type& k, const value_type& v)
    {
        auto add = [&] {
            key_value_ptr ptr = std::make_shared<key_value_type>(k, v);
            _map.emplace(k, ptr);
            _set.insert(ptr);
        };

        auto it = _map.find(k);
        if (it == _map.end())
        {
            if (_set.size() < _top)
            {
                add();
            }
            else if (_set.size() == _top)
            {
                auto val = v;
                if (val < (*_set.begin())->second)
                    return;

                _map.erase((*_set.begin())->first);
                _set.erase(_set.begin());
                add();
            }
        }
        else
        {
            _set.erase(it->second);
            _map.erase(it);
            add();
        }
    }

    void erase(const key_type& k) {
        auto it = _map.find(k);

        if (it == _map.end())
            return;

        _set.erase(it->second);
        _map.erase(it);
    }

    void clear() {
        _set.clear();
        _map.clear();
    }

    size_type size() { return _set.size(); }

    size_type rank(const key_type& k) {
        auto it = _map.find(k);

        if (it == _map.end() || _set.empty())
            return 0;

        size_type rank = 0;

        for (auto n = _set.rbegin(); n != _set.rend(); ++n) {
            ++rank;
            if ((*n)->first == k)
                return rank;
        }

        return 0;
    }

private:
    size_type _top;
    std::unordered_map<key_type, key_value_ptr> _map;
    std::set<key_value_ptr, key_value_less> _set;
};

struct Rank
{
    int _trophy = 0;
    int _chicken = 0;

    bool operator<(const Rank& r)
    {
        if (_chicken == r._chicken)
            return _trophy > r._trophy;

        return _chicken < r._chicken;
    }

    bool operator==(const Rank& r)
    {
        return _trophy == r._trophy && _chicken == r._chicken;
    }

    //Rank operator+(const Rank& r)
    //{
    //    return Rank(this->_chicken + r._chicken, this->_trophy + r._trophy);
    //}

    friend Rank operator+(const Rank& l, const Rank& r);
    Rank(int chicken, int trophy) :_chicken(chicken), _trophy(trophy) {}
};

Rank operator+(const Rank& l, const Rank& r)
{

    return Rank(l._chicken + r._chicken, l._trophy + r._trophy);
}