//
//  proxy.cpp
//  Stuctural_paterns
//
//  Created by Polina on 06.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

class VeryHeavyDB{
public:
    std::string GetData(const std::string& key) const noexcept{
        return "Big data string: " + key + '\n';
    }
};

class CacheProxyDB:public VeryHeavyDB{
public:
    explicit CacheProxyDB(VeryHeavyDB* real_obj):big_data(real_obj){};
     std::string GetData(const std::string& key)noexcept{
        if (cache.find(key) == cache.end()){
            std::cout << "Get from real obj\n";
            cache[key] = big_data->GetData(key);
        }
        else
            std::cout << "Get from cache\n";
        return cache.at(key);
    }
private:
    VeryHeavyDB* big_data;
    std::map<std::string, std::string> cache;
};

class TestDB: VeryHeavyDB{
public:
    explicit TestDB (VeryHeavyDB* real_obj): heavy_data(real_obj){};
    std::string GetData(const std::string& text_data)noexcept{
        return "test data\n";
    }
private:
    VeryHeavyDB* heavy_data;
};

class OneShotDB: public VeryHeavyDB{
public:
    explicit OneShotDB(VeryHeavyDB* real_obj, size_t size):big_data(real_obj), size_(size){};
    std::string GetData(const std::string& text_data) noexcept{
       ++count;
       if (count > size_)
           return "error\n";
       else
           return "value\n";
   }
private:
    VeryHeavyDB* big_data;
    size_t size_;
    int count = 0;
};

int main (){
    
//    auto real_obj = VeryHeavyDB();
//    auto cache_db = CacheProxyDB(std::addressof(real_obj));
//    auto test_db = TestDB(std::addressof(real_obj));
//
//    std::cout << real_obj.GetData("key");
//    std::cout << cache_db.GetData("key");
//    std::cout << test_db.GetData("key");
    
    auto real_db = VeryHeavyDB();
    auto limit_db = OneShotDB(std::addressof(real_db), 2);
    
    std::cout << limit_db.GetData("key");
    std::cout << limit_db.GetData("key");
    std::cout << limit_db.GetData("key");
    
    return 0;
}
