

/*
 Farming is competitive business -- particularly milk production. Farmer John figures that if he doesn't innovate in his milk production methods, his dairy business could get creamed!
 Fortunately, Farmer John has a good idea. His three prize dairy cows Bessie, Elsie, and Mildred each produce milk with a slightly different taste, and he plans to mix these together to get the perfect blend of flavors.
 
 To mix the three different milks, he takes three buckets containing milk from the three cows. The buckets may have different sizes, and may not be completely full. He then pours bucket 1 into bucket 2, then bucket 2 into bucket 3, then bucket 3 into bucket 1, then bucket 1 into bucket 2, and so on in a cyclic fashion, for a total of 100 pour operations (so the 100th pour would be from bucket 1 into bucket 2). When Farmer John pours from bucket aa into bucket bb, he pours as much milk as possible until either bucket aa becomes empty or bucket bb becomes full.
 
 Please tell Farmer John how much milk will be in each bucket after he finishes all 100 pours.
 */

#include <iostream>
#include <fstream>
using namespace std;


int main() {
    
    ifstream in_file;
    in_file.open("mixmilk.in");
    if (in_file.fail())
    {
        cout << "error";
    }
    
    
    int c1;
    in_file >> c1;
    
    int m1;
    in_file >> m1;
    
    
    int c2;
    in_file >> c2;
    
    int m2;
    in_file >> m2;
    
    int c3;
    in_file >> c3;
    
    int m3;
    in_file >> m3;
    
    
    
    for (int i = 1; i <= 33; i++) {
        //Bucket 1 to Bucket 2
        if ((m1 + m2) <= c2) {
            m2 = m1 + m2;
            m1 = 0;
        }else if ((m1 + m2) > c2){
            m1 = (m1 + m2) - c2;
            m2 = c2;
        }
        //Bucket 2 to Bucket 3
        if ((m2 + m3) <= c3) {
            m3 = m2 + m3;
            m2 = 0;
        }else if ((m2 + m3) > c3){
            m2 = (m2 + m3) - c3;
            m3 = c3;
        }
        
        //Bucket 3 to Bucket 1
        
        if ((m3 + m1) <= c1) {
            m1 = m3 + m1;
            m3 = 0;
        }else if ((m3 + m1) > c1) {
            m3 = (m1 + m3) - c1;
            m1 = c1;
        }
        
        
    }
    
    //Bucket 1 to Bucket 2
    if ((m1 + m2) <= c2) {
        m2 = m1 + m2;
        m1 = 0;
    }else if ((m1 + m2) > c2){
        m1 = (m1 + m2) - c2;
        m2 = c2;
    }
    
    
    cout << m1 << endl;;
    cout << m2 << endl;;
    cout << m3 << endl;
    
    
    ofstream out_file;
    out_file.open("mixmilk.out");
    out_file << m1;
    out_file << m2;
    out_file << m3;
    
    
    
    
    
    
    
}