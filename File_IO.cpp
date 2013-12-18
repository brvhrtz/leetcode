/*
 * C12P3
 * Given an input file with 4 billion integers, 
 * Generate an integer which is not contained in the file. 
 * Assume you have 1 GB of memory. 
 * FOLLOW UP What if you have only 10 MB of memory? 
 */
 
#include <iostream>
#include <fstream>
#include <vector> 
#include <algorithm>

using namespace std;

    struct node
    {
      int key_value;
      int index;
    };
    
    bool node_compare(node *a, node *b)
    {
        return a->key_value < b->key_value? true : false;
    }
    
int main()
{
    ifstream inFile;
    inFile.open("input.txt");
    // simply ifstream ifile("input.txt");
    
    if(inFile.fail())
    {
        cerr << "Error openning file!" << endl; 
        exit(0);
    }
    
    int holder;
    vector<int> vec; 
    if(inFile.is_open())
    {
        while(inFile >> holder) vec.push_back(holder); 
    }
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl; 
    
    vector<node *> nvec;
    node *temp;
        
    for(int i = 0; i < vec.size(); i++)
    {
        temp = new node;
        temp->key_value = vec[i];
        temp->index = i;
        nvec.push_back(temp);
    }
    
    std::sort(nvec.begin(), nvec.end(), node_compare);
    for(int i = 0; i < nvec.size(); i++)
    {
        cout << nvec[i]->key_value << " " << nvec[i]->index << endl; 
    }
    
    
    inFile.close();
    
    return 0;
}
