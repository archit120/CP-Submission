
#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Trie
{
	// true when node is a leaf node
	bool isLeaf;
    int count;
	// each node stores a map to its child nodes
	unordered_map<char, Trie*> map;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->isLeaf = false;
    node->count=0;
	return node;
}

void insert(Trie*& head, char* str)
{
	if (head == nullptr)
        head = getNewTrieNode();

	Trie* curr = head;
    curr->count++;
	while (*str)
	{
		if (curr->map.find(*str) == curr->map.end())
			curr->map[*str] = getNewTrieNode();
		curr = curr->map[*str];
        curr->count++;
		str++;
	}
	curr->isLeaf = true;
}

// returns true if given node has any children
bool haveChildren(Trie const* curr)
{
	// don't use (curr->map).size() to check for children

	for (auto it : curr->map)
		if (it.second != nullptr)
			return true;

	return false;
}

bool deletion(Trie*& curr)
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

    for(auto i : curr->map)
    {
        deletion(i.second);
    }
	
   delete curr;
    return true;

}
tuple<int, int> search(Trie* head, Trie* root)
{
	// return false if Trie is empty
	if (head == nullptr)
		return make_tuple(0,0);

	Trie* curr = head;
    if(head->count <= 1)
        return make_tuple(0,0);
    int out = 0;
    int pout = 0;
   // cout << "IN\n";
    for(auto j : head->map)
    {
        if(!j.second)   continue;
        auto t = search(j.second, root);
        int t1= get<0>(t);
        int t2 = get<1>(t);
        pout+=t2;
        out+=t1;
        //cout << j.first << " " << out <<" " << j.second->count<<" " << pout <<  "\n";
    }
    if(head != root)
	{
        out+=(head->count - pout) >= 2 ? 2 : 0;
        if(head->count-pout>=2)
        {
            pout += 2;
        }
    }
    //cout << out <<" " << pout<< " OUT\n";

	return make_tuple(out, pout);
}


string get_suffix(string a, string b)
{
    string sf = "";
    for(int i =0;i<min(a.size(),b.size()); i++)
    {
        if(a[i]!=b[i])
            break;
        sf += a[i];
    }
    return sf;
}

int main()
{
    IOS
    
    int t;
    cin >> t;
    int t2 = t;
    while(t--)
    {
        int n;
        cin >> n;
        int out = 0;
        vector<string> words;

        Trie* root;
        root = getNewTrieNode();
        root->count=0;
        for(int i =0;i<n;i++)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            insert(root, (char*)s.c_str());
            words.push_back(s);
        }

        sort(words.begin(), words.end());

      
        cout << "Case #" << (t2-t) <<": " << get<0>(search(root, root)) <<"\n";
        delete(root);
    }
}
