#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <limits>
#include <exception>
#include <vector>
#include <algorithm>
#include <set>

class graph{
public:
    void add_vertice(std::string from, std::string where, double weight){
        _graph[from][where] = weight;
        _size++;
        _vertices.insert(from);
        _vertices.insert(where);
    }

    void print_graph(){
        for (auto &i : _graph){
            for (auto &j : i.second){
                std::cout << i.first << " -> " << j.first << " = " << j.second << std::endl;
            }
        }
    }

    void print_costs(){
        for (auto &i : _costs){
            std::cout << i.first << " = " << i.second << std::endl;
        }
    }

    void print_parents(){
        for (auto &i : _parents){
            std::cout << i.second << " is a parent of " << i.first << std::endl;
        }
    }

    void dijkstra(std::string start){
        bool flag = true;
        for (auto &i : _vertices){
            _costs[i] = std::numeric_limits<double>::infinity();
            if (i == start) flag = false;
        }
        if (flag) {throw std::exception(); return;}
        _costs[start] = 0;
        std::vector<std::string> processed;
        while (_size != processed.size()){
            std::string curr_vertice = min_not_processed_vertice(processed);
            processed.push_back(curr_vertice);
            for (auto &j : _graph[curr_vertice]){
                if (_costs[curr_vertice] + j.second < _costs[j.first]){
                    _costs[j.first] = _costs[curr_vertice] + j.second;
                    _parents[j.first] = curr_vertice;
                }
            }
        }
    }

    void bellman_ford(std::string start){
        bool flag = true;
        for (auto &i : _vertices){
            _costs[i] = std::numeric_limits<double>::infinity();
            if (i == start) flag = false;
        }
        if (flag) {throw std::exception(); return;}
        _costs[start] = 0;
        size_t iterations = _vertices.size()-1;
        for (size_t iter = 0; iter < iterations; ++iter){
            flag = true;
            for (auto &i : _vertices){
                if (_costs[i] != std::numeric_limits<double>::infinity()){
                    for (auto &j : _graph[i]){
                        if (_costs[i] + j.second < _costs[j.first]){
                            _costs[j.first] = _costs[i] + j.second;
                            _parents[j.first] = i;
                            flag = false;
                        }
                    }
                }
            }
            if (flag) return;
        }
    }

private:
    std::unordered_map<std::string,std::unordered_map<std::string, double>> _graph;
    std::unordered_map<std::string,double> _costs;
    std::unordered_map<std::string, std::string> _parents;
    std::set<std::string> _vertices;
    size_t _size = 0;

    std::string min_not_processed_vertice(std::vector<std::string> proc){
        std::string res;
        size_t min_cost = std::numeric_limits<double>::infinity();
        for (auto &i : _vertices){
            if (std::find(proc.begin(), proc.end(), i) == proc.end()){
                if (_costs[i] < min_cost){
                    min_cost = _costs[i];
                    res = i;
                }
            }
        }
        return res;
    }
};

#endif // GRAPH_H
