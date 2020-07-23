#ifndef JUG_H
#define JUG_H

#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <list>
#include <stack>
#include <sstream>
using namespace std;

class Vertex
{
    friend class Jug;
    public:
        Vertex(int, int);
    private:
        int Amount_A;
        int Amount_B;
        int previous;
        unsigned int Dist;
        bool unvisited;
        vector<pair<unsigned int, string>> neighbors;
};

class Jug {
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.

        int solve(string &solution);

    private:
        //capacity of A
        int Ca;
        //capacity of B
        int Cb;
        //Goal
        int N;
        //the cost to fill A
        int cfA;
        //the cost to fill B
        int cfB;
        //the cost to empty A
        int ceA;
        //the cost to empty B
        int ceB;
        //the cost to pour A to B
        int cpAB;
        //the cost to pour A to B
        int cpBA;

        //Helper functions
        stack<unsigned int> process;
        vector<unsigned int> visited;
        vector<Vertex> Vert;
        stack<string> traverse;
        void graph();
        unsigned int Fill_A(unsigned int);
        unsigned int Fill_B(unsigned int);
        unsigned int Empty_A(unsigned int);
        unsigned int Empty_B(unsigned int);
        unsigned int Pour_AB(unsigned int);
        unsigned int Pour_BA(unsigned int);
        string Dijkstra();
        int getCost(string input) const;
};

#endif