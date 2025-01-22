#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     unordered_set<int> u;
//     cout<<"Bucket count is "<<u.bucket_count()<<endl;
//     for(int i=0;i<10;i++){
//         u.insert(i);
//         cout<<"Bucket count after "<<i<< " is "<<u.bucket_count()<<endl;
//     }
//     cout<<"Load factor is "<<u.load_factor()<<endl;
//     cout<<"Max load factor is "<<u.max_load_factor()<<endl;
//     cout<<"Bucket count is "<<u.bucket_count()<<endl;
//     cout<<"Max Bucket count is "<<u.max_bucket_count()<<endl;
//     cout<<"Load factor is "<<u.load_factor()<<endl;
    

//     return 0;
// }


int main() {
    std::unordered_set<std::vector<int>> result;

    result.insert({1, 2, 3});
    result.insert({4, 5, 6});
    result.insert({1, 2, 3}); // Duplicate

    for (const auto& vec : result) {
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
