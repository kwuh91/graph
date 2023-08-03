#include <graph.h>

int main(){
    /*
    ////////////////////////////////////////
    graph graph_obj;

    //frist graph for dijkstra
    //graph_obj.add_vertice("start","A",6);
    //graph_obj.add_vertice("start","B",2);
    //graph_obj.add_vertice("A","end",1);
    //graph_obj.add_vertice("B","A",3);
    //graph_obj.add_vertice("B","end",5);

    //second graph for dijkstra
    graph_obj.add_vertice("start","a",5);
    graph_obj.add_vertice("start","b",2);
    graph_obj.add_vertice("a","c",4);
    graph_obj.add_vertice("a","d",2);
    graph_obj.add_vertice("b","a",8);
    graph_obj.add_vertice("b","d",7);
    graph_obj.add_vertice("c","d",6);
    graph_obj.add_vertice("c","end",3);
    graph_obj.add_vertice("d","end",1);

    std::cout << "Initial status" << std::endl;
    graph_obj.print_graph();
    std::cout << std::endl;
    graph_obj.dijkstra("start");

    std::cout << "End status" << std::endl;
    graph_obj.print_costs();
    std::cout << std::endl;
    graph_obj.print_parents();
    std::cout << std::endl;
    ////////////////////////////////////////
    */
    graph graph_obj;

    //graph for bellman-ford
    graph_obj.add_vertice("s","e",8);
    graph_obj.add_vertice("s","a",10);
    graph_obj.add_vertice("a","c",2);
    graph_obj.add_vertice("b","a",1);
    graph_obj.add_vertice("c","b",-2);
    graph_obj.add_vertice("d","c",-1);
    graph_obj.add_vertice("d","a",-4);
    graph_obj.add_vertice("e","d",1);

    std::cout << "Initial status" << std::endl;
    graph_obj.print_graph();
    std::cout << std::endl;
    graph_obj.bellman_ford("s");

    std::cout << "End status" << std::endl;
    graph_obj.print_costs();
    std::cout << std::endl;
    graph_obj.print_parents();
    std::cout << std::endl;

    return 0;
}
