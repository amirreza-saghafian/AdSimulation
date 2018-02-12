//
// Created by Amirreza Saghafian on 2/11/18.
// A data container to cache data.
// Apply least recently used (LRU) policy for cache evictions.
// As recommended in the google C++ style guide, the template definitions are
// included in the header file and not in the cc file.
//

#ifndef DEMO_LRU_CACHE_H
#define DEMO_LRU_CACHE_H

#include <vector>
#include <list>
#include <iterator>
#include <unordered_map>
#include <iostream>

using std::unordered_map;

// LRU Cache class
// I: is the type of item_'s index
// T: is the item_ type
// Example:
// LruCache<string, Item> ads_cache;
// ads_cache.Lookup("Nike");
// Example:
// LruCache<int, double> price_cache;
template <class I, class T>
class LruCache {
 public:

  explicit LruCache(size_t capacity = 100);
  void Insert(const I& id, const T& item);
  void Delete(const I& id);
  T Lookup(const I& id) const;
  void Print() const;
  size_t GetCapacity() const;
  void SetCapacity(size_t capacity);
  size_t GetNumberOfItemsInCache() const;

 private:

  // recency list: least recently used item_ is at the back, and most recently
  // used item_ is at the front of the list.
  std::list<I> items_recency_list_;

  // Hash table to map item_'s identity to the pair of item_ and
  // its recency list iterator.
  unordered_map<I, std::pair<T, typename std::list<I>::iterator>> items_ht_;

  // Total number of cache capacity.
  size_t cache_capacity_;
};


// Template definitions.
template <class I, class T>
LruCache<I, T>::LruCache(size_t capacity) :
    cache_capacity_(capacity) {
}

template <class I, class T>
void LruCache<I, T>::Insert(const I& id, const T& item) {
  auto item_it = items_ht_.find(id);

  // Item is already in the cache.
  // Need to update it (i.e. remove from hash table if it has change and add),
  // and also move to the front of recency list.
  if (item_it != items_ht_.end()) {
    // update the recency list
    items_recency_list_.erase(items_ht_[id].second);
    items_recency_list_.emplace_front(id);
    items_ht_.erase(id);
    items_ht_[id] = std::make_pair(item, items_recency_list_.begin());
    return;
  }

  // Item is not in the cache.
  // Should be added to hash table and front of the recency list.
  // Need to evict the least recently used item_ in case number of items is
  // more than the cache capacity.
  if (items_ht_.size() >= cache_capacity_) {
    items_ht_.erase(items_recency_list_.back());
    items_recency_list_.pop_back();
  }

  items_recency_list_.emplace_front(id);
  items_ht_[id] = std::make_pair(item, items_recency_list_.begin());
}

template <class I, class T>
void LruCache<I, T>::Delete(const I &id) {
  auto item_it = items_ht_.find(id);

  if (item_it == items_ht_.end()) {
    throw std::invalid_argument("LruCache::Delete(): "
                                    "Item is not in the cache!");
  }

  items_recency_list_.erase(items_ht_[id].second);
  items_ht_.erase(item_it);
}

template <class I, class T>
T LruCache<I, T>::Lookup(const I &id) const {
  auto item_it = items_ht_.find(id);

  if (item_it == items_ht_.end()) {
    throw std::invalid_argument("LruCache::Lookup(): "
                                    "Item is not in the cache!");
  }

  return item_it->second.first;
}

template <class I, class T>
void LruCache<I, T>::Print() const {
  for (const auto& item : items_ht_) {
    std::cout << item.first << "->" << (item.second).first << std::endl;
  }

  std::cout << std::endl;
}

template <class I, class T>
size_t LruCache<I, T>::GetCapacity() const {
  return cache_capacity_;
}

template <class I, class T>
void LruCache<I, T>::SetCapacity(const size_t capacity) {
  cache_capacity_ = capacity;
}

template <class I, class T>
size_t LruCache<I, T>::GetNumberOfItemsInCache() const {
  return items_ht_.size();
}

#endif //DEMO_LRU_CACHE_H
