#ifndef OGRAPH
#define OGRAPH

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>

#ifdef SPARSE_HASH
    #include <sparsehash/sparse_hash_map>
    #include <sparsehash/dense_hash_map>
    #include <sparsehash/dense_hash_set>

    #define unordered_map sparse_hash_map
    #define unordered_map dense_hash_map
    #define unordered_set dense_hash_set
#else
    #include <unordered_map>
    #include <unordered_set>

#endif /* SPARSE_HASH */

using namespace std;

void create_hash_function_from_m_mers(int m);
void count_m_mers(string str, int m, int k);
void init_m_mers_table(int m);

typedef unordered_map<string,int> HashMap;


HashMap build_hash_map(int len);

int shash(const string& s, int& previous_shash, unsigned int start_pos = 0, int length = -1);

string inverse_shash (int num, int len);

int minimiserrc(const string &node,const int &minimisersize);

int minbutbiggerthan(int leftmin, int rightmin, const string &namebucket);

string reversecompletment(const string& str );

bool adjacent (const string& node1,const  string& node2,int k);

string readn(ifstream *file,uint64_t n);

string minimalsub(const string &w, const int &p,const int &k);

string minimalsub2(const string &w, const int &p,const int &k);

class neighbour
{
	public:
		array<pair<uint64_t,unsigned char>,8> list;
		//~ neighbour()
		//~ {
			//~ for(int )
			//~ list[i]=make_pair(0,0);
		//~ }
		uint64_t nbtype(unsigned char c);
		uint64_t gtype(unsigned char c);

		void add(uint64_t p,unsigned char b);
		unsigned char remove(uint64_t v);
		unsigned char removep(uint64_t v,unsigned char c);
		unsigned char removetype(unsigned char c);

};

class graph1
{
	public:
		uint32_t n;
		int k;
		vector<string> nodes;
		vector<int> leftmins;
		vector<int> rightmins;
		unordered_multimap<uint64_t,uint32_t> map;
		unordered_multimap<uint64_t,uint32_t> maprev;
		vector<neighbour> neighbor;

		graph1(const int ni)
		{
			k=ni;
			n=1;
			nodes.push_back("");
			leftmins.push_back(-1);
			rightmins.push_back(-1);
		}

		uint64_t getkey(const string& str);
		uint64_t getkeyrevc(const string& str);
		uint64_t becompacted(uint64_t nodeindice, int min, unsigned char *);
		int weight();
		void addvertex(const string& str);
        void addleftmin(int mini);
        void addrightmin(int mini);
		void debruijn();
		void compressh(int min=-1);
		void compress();
		void importg(const char *name);
		void print(const char *name);
		void printedges(const char *name);
		void compact(uint64_t nodeindice,uint64_t with, unsigned char type);
		void reverse(int64_t with);
		void look(const uint64_t nodeindice, const string& min);
};


class graph2
{
	public:
		int k;
		int minimizer;
		int minsize;
		uint64_t weight;
		//~ ofstream outFile;
		vector<string> unitigs;
		vector<bool> leftmins;
		vector<bool> rightmins;
		unordered_map<uint64_t,uint32_t> left2unitig;
		unordered_map<uint64_t,uint32_t> right2unitig;
		//~ dense_hash_set<uint64_t> multiple;
		//~ unordered_set<uint64_t> multiple;
		
		void addvertex(const string& str);
		void addleftmin(int mini);
		void addrightmin(int mini);
		void debruijn();
		void compress();
		void compress2();
		void print();
		void chainCompaction(uint32_t i,string unitig, uint32_t next);
		void chainCompaction2(uint32_t i,string unitig, uint32_t next);
		uint32_t leftUnique(uint64_t);
		uint32_t rightUnique(uint64_t);
		uint32_t goBeg(uint32_t i);
		uint32_t goEnd(uint32_t i);
		uint32_t size();
		
		graph2(int ka, int min,int size)
		{
			minsize=size;
			k=ka;
			minimizer=min;
			//~ multiple.set_empty_key(-1);
//			left2unitig.set_empty_key(-1);
//			right2unitig.set_empty_key(-1);
			unitigs.push_back("");
			leftmins.push_back(-1);
			rightmins.push_back(-1);
		}
};

#endif
