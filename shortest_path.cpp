// Shania Jain
// Lab 3
// Finds the shortest path in any graph whose vertices and path lengths are inputted by the user


#include <iostream>
using namespace std;



//finds the minimum vertex
int findMin(int* distance, bool* previous, int vertices)
{
    int min = -1;
    for (int i = 0; i < vertices; i++) {
        if (!previous[i] && (min == -1 || distance[i] < distance[min]))
        {
            min = i;
        }
    }
    return min;
}


//find the shortest path between two vertices
void shortest_path(int** adj_matrix, int vertices)
{
    int* distance = new int[vertices];
    bool* previous = new bool[vertices];
    
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        previous[i] = false;
    }
    
    distance[0] = 0;
    
    for (int i = 0; i < vertices - 1; i++)
    {
        int min = findMin(distance, previous, vertices);
        previous[min] = true;
        
        for (int j = 0; j < vertices; j++)
        {
            if (adj_matrix[min][j] != 0 && !previous[j])
            {
                int dis = distance[min] + adj_matrix[min][j];
                if(dis < distance[j])
                {
                    distance[j] = dis;
                }
            }
        }
        
    }
    
    
    //prints the shortest path such that vertex number is displayed on the left and path length is displayed on the right
    cout << "vertex:" << "     " << "path length:" << endl;
    for(int i = 0; i < vertices; i++)
    {
        cout << i << "          " << distance[i] << endl;
    }
    
    delete [] previous;
    delete [] distance;

}



int main()
{
    int vertices;
    int edges;
    
    cout << "number of vertices: ";
    cin >> vertices;
    
    cout << "number of edges: ";
    cin >> edges;
    
    int** adj_matrix = new int*[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adj_matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    
    //input the distance between two vertices in the graph
    for (int i = 0; i < edges; i++)
    {
        int a, b, path_length; //int a and int b refer to two vertices
        cout << "enter the two vertices and their distance (a, b, length): ";
        cin >> a >> b >> path_length;
        
        adj_matrix[a][b] = path_length;
        adj_matrix[b][a] = path_length;
    }
    
    //call shortest_path function
    shortest_path(adj_matrix, vertices);
    
    for (int i = 0; i < vertices; i++)
    {
        delete [] adj_matrix[i];
    }
    delete [] adj_matrix;
    
    
}
