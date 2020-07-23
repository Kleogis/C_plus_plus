//Created by Viktoriia Liu, Jayden Lui and Kevin Brewer
// Pairing technique : https://www.geeksforgeeks.org/pair-in-cpp-stl/
#include "Jug.h"

Vertex::Vertex(int amountA, int amountB)
{
    previous = -1;
    Dist = UINT_MAX;
    unvisited = false;
    Amount_A = amountA;
    Amount_B = amountB;
}

//Constructor
Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA){
  this->Ca = Ca;
  this->Cb = Cb;
  this->N = N;
  this->cfA = cfA;
  this->cfB = cfB;
  this->ceA = ceA;
  this->ceB = ceB;
  this->cpAB = cpAB;
  this->cpBA = cpBA;
}

Jug::~Jug(){}   

int Jug::solve(string &solution){
  if(Ca < 1 || Cb < 1 || Cb > 1000 || Ca > Cb || N < 0 || N > Cb || cfA < 0 || cfB < 0 || ceA < 0 || ceB < 0 || cpAB < 0 || cpBA < 0){
    solution = ""; 
    return -1;
  } 
  Vertex empty(0, 0);
  Vert.push_back(empty);
  process.push(0);
  graph();
    
  string success;
  success = Dijkstra();
  if(success.empty()){
    return 0;
  }
  while(!traverse.empty()){
    solution += (traverse.top() + '\n');
    traverse.pop();
  }
  solution += success;
  return 1;
}

void Jug::graph(){
  while(!process.empty()){
    bool found = false;
    unsigned int current = process.top();
    process.pop();
    for(unsigned int i = 0; i < visited.size(); i++){
      if(current == visited.at(i)){
        found = true;
        break;
      }
    }
    if(!found){
      visited.push_back(current);
      process.push(Fill_A(current) );
      process.push(Fill_B(current) );
      process.push(Empty_A(current) );
      process.push(Empty_B(current) );
      process.push(Pour_AB(current) );
      process.push(Pour_BA(current) );
    }
  }
}
//To fill A jug
unsigned int Jug::Fill_A(unsigned int current)
{
    unsigned int index;
    bool found = false;
    Vertex neighbor(Ca, Vert.at(current).Amount_B);
    
    for(unsigned i = 0; i < Vert.size(); i++){
      if(Vert.at(i).Amount_A == neighbor.Amount_A && Vert.at(i).Amount_B == neighbor.Amount_B){
        index = i;
        found = true;   
        break;
      }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found){
      pairing = make_pair(index, "fill A");
    }
    else
    {
      Vert.push_back(neighbor);
      pairing = make_pair(Vert.size() - 1, "fill A");
    }
    Vert.at(current).neighbors.push_back(pairing);
    return Vert.at(current).neighbors.back().first;
}

//To fill B jug
unsigned int Jug::Fill_B(unsigned int current){
  unsigned int index;
  bool found = false;
  Vertex neighbor(Vert.at(current).Amount_A, Cb);
  for(unsigned i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == neighbor.Amount_A && Vert.at(i).Amount_B == neighbor.Amount_B){
      index = i;
      found = true;  
      break;
    }
  }
  pair<unsigned int, string> pairing;
  if(found){
    pairing = make_pair(index, "fill B");
  }
  else{
    Vert.push_back(neighbor);
    pairing = make_pair(Vert.size() - 1, "fill B");
  }
  Vert.at(current).neighbors.push_back(pairing);
  return Vert.at(current).neighbors.back().first;
}

//Empty A jug
unsigned int Jug::Empty_A(unsigned int current){
  unsigned int index;
  bool found = false;
  Vertex neighbor(0, Vert.at(current).Amount_B);
  for(unsigned i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == 0 && Vert.at(i).Amount_B == neighbor.Amount_B){
      index = i;
      found = true;
      break;
    }
  }
  pair<unsigned int, string> pairing;
  if(found){
    pairing = make_pair(index, "empty A");
  }
  else{
    Vert.push_back(neighbor);
    pairing = make_pair(Vert.size() - 1, "empty A");
  }
  Vert.at(current).neighbors.push_back(pairing);
  return Vert.at(current).neighbors.back().first;
}

//Empty B jug
unsigned int Jug::Empty_B(unsigned int current){
  unsigned int index;
  bool found = false;
  Vertex neighbor(Vert.at(current).Amount_A, 0);
  for(unsigned i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == neighbor.Amount_A && Vert.at(i).Amount_B == 0){
      index = i;
      found = true;  
      break;
    }
  }
  pair<unsigned int, string> pairing;
  if(found){
    pairing = make_pair(index, "empty B");
  }
  else{
    Vert.push_back(neighbor);
    pairing = make_pair(Vert.size() - 1, "empty B");
  }
    Vert.at(current).neighbors.push_back(pairing);
    return Vert.at(current).neighbors.back().first;
}

//Pour water from A to B
unsigned int Jug::Pour_AB(unsigned int current){
  unsigned int index;
  bool found = false;
  int neighborA = Vert.at(current).Amount_A;
  int neighborB = Vert.at(current).Amount_B;
  while(neighborA > 0 && neighborB < Cb){
    neighborA = neighborA - 1 ;
    neighborB = neighborB + 1;
  }
  Vertex neighbor(neighborA, neighborB);
  for(unsigned i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == neighbor.Amount_A && Vert.at(i).Amount_B == neighbor.Amount_B){
      index = i;
      found = true; 
      break;
    }
  }
  pair<unsigned int, string> pairing;
  if(found){
    pairing = make_pair(index, "pour A B");
  }
  else{
    Vert.push_back(neighbor);
    pairing = make_pair(Vert.size() - 1, "pour A B");
  }
  Vert.at(current).neighbors.push_back(pairing);
  return Vert.at(current).neighbors.back().first;
}

//Pout water from B into A
unsigned int Jug::Pour_BA(unsigned int current){
  unsigned int index;
  bool found = false;
  int neighborA = Vert.at(current).Amount_A;
  int neighborB = Vert.at(current).Amount_B; 
  while(neighborA < Ca && neighborB > 0){
    neighborA = neighborA + 1;
    neighborB = neighborB - 1;
  }
  Vertex neighbor(neighborA, neighborB);
  for(unsigned i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == neighbor.Amount_A && Vert.at(i).Amount_B == neighbor.Amount_B){
      index = i;
      found = true;
      break;
    }
  }
  pair<unsigned int, string> pairing;
  if(found){
    pairing = make_pair(index, "pour B A");}
  else{
    Vert.push_back(neighbor);
    pairing = make_pair(Vert.size() - 1, "pour B A");
  }
  Vert.at(current).neighbors.push_back(pairing); 
  return Vert.at(current).neighbors.back().first;
}

int Jug::getCost(string input) const
{
    if(input == "fill A"){
      return cfA;
    }
    else if(input == "fill B"){
      return cfB;
    }
    else if(input == "empty A"){
      return ceA;
    }
    else if(input == "empty B"){
      return ceB;
    }
    else if(input == "pour A B"){
      return cpAB;
    }
    else{
      return cpBA;
    }
}

string Jug::Dijkstra(){
  for(unsigned int i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == 0 && Vert.at(i).Amount_B == N){
      break;
    }
    else if(i == Vert.size() - 1){
      return "";
    }
  }
  vector<Vertex *> unvisited;
  unsigned index;
  for(unsigned i = 0; i < Vert.size(); i++){
    Vertex *pointer = &Vert.at(i);
    unvisited.push_back(pointer);
  }
  unvisited.at(0)->Dist = 0;
  while(!unvisited.empty() ){
    unsigned int minimum = 0;
    for(unsigned int i = 0; i < unvisited.size(); i++){
      if(unvisited.at(i)->Dist < unvisited.at(minimum)->Dist){
        minimum = i;
      }
    }
    for(unsigned int i = 0; i < Vert.size(); i++){
      if(Vert.at(i).Amount_A == unvisited.at(minimum)->Amount_A && Vert.at(i).Amount_B == unvisited.at(minimum)->Amount_B){
        index = i;
      }
    }
    for(unsigned i = 0; i < unvisited.at(minimum)->neighbors.size(); i++){
      unsigned int alternate = unvisited.at(minimum)->Dist + getCost(unvisited.at(minimum)->neighbors.at(i).second);
      if(Vert.at(unvisited.at(minimum)->neighbors.at(i).first).Dist > alternate){
        Vert.at(unvisited.at(minimum)->neighbors.at(i).first).Dist = alternate;
        Vert.at(unvisited.at(minimum)->neighbors.at(i).first).previous = index;
      }
    }
    unvisited.erase(unvisited.begin() + minimum);
  }
  for(unsigned int i = 0; i < Vert.size(); i++){
    if(Vert.at(i).Amount_A == 0 && Vert.at(i).Amount_B == N){
      index = i; 
      break;
    }
  }
  unsigned int shortest = Vert.at(index).Dist;
  while(Vert.at(index).previous != -1){
    for(unsigned int i = 0; i < Vert.at(Vert.at(index).previous).neighbors.size(); i++){
      if(Vert.at(Vert.at(index).previous).neighbors.at(i).first == index){
        traverse.push(Vert.at(Vert.at(index).previous).neighbors.at(i).second); 
        break;
      }
    }
    index = Vert.at(index).previous;
  }
  stringstream ss;
  ss << shortest;
  return "success " + ss.str();
}

