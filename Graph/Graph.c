#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

//Structure for the connected vertices to a particular vertex

struct node_edge{
	int data;
	struct node_edge *nextedge;
	int status;
};

 //Structure for the vertex 

struct node_vertex{
	int data;
	struct node_edge *link;
	struct node_vertex *nextvertex;
	int status;
};
struct node_vertex *head=NULL;        //Starting vertex


//Function Declaration

struct node_vertex *create_v(struct node_vertex*,int);
struct node_edge *create_e(struct node_vertex*,int ,int);
void print(struct node_vertex*);
void delete_edge(struct node_vertex*,int,int);
void delete_vertex(int);
void initiate(struct node_vertex*);
int statechange(int);
void BFT(int);
void DFT(int);
int visit(int);


//Function to create a vertex

struct node_vertex *create_v(struct node_vertex* ptr,int m){                 //ptr-Starting vertex(head),m-Vertex value
	if(ptr==NULL){															//Adding the first vertex
		struct node_vertex *newvertex;
		newvertex=(struct node_vertex*)malloc(sizeof(struct node_vertex));
		newvertex->data=m;
		newvertex->nextvertex=NULL;
		newvertex->link=NULL;
		return newvertex;
	}else{
		ptr->nextvertex=create_v(ptr->nextvertex,m);
	}
	
}


//Function to create an edge

struct node_edge *create_e(struct node_vertex *ptr,int x,int y){    //ptr- Pointer to the starting vertex,x-Source vertex,y-Destination vertex
	while(ptr->data!=x){                             //Locate vertex x
		ptr=ptr->nextvertex;
	}
	struct node_edge *edge=ptr->link;
	if(edge!=NULL){									//If vertex has edges, Locate the end point
		while(edge->nextedge!=NULL){
			edge=edge->nextedge;
		}
		struct node_edge *newedge;										//Create the new edge
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));
		newedge->data=y;
		newedge->nextedge=NULL;
		edge->nextedge=newedge;	
	}else{
		struct node_edge *newedge;										//If the vertex has no edges Create the new edge
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));	//as the first edge
		newedge->data=y;
		newedge->nextedge=NULL;
		ptr->link=newedge;
	}	
}


//Function to print the graph

void print(struct node_vertex *ptr){                //ptr-Pointer to the starting vertex(head)
	struct node_edge *edge;
	printf("Vertex\t        Edge\n\n");
	while(ptr!=NULL){								//Traverse each vertex
		printf("%d\t\t",ptr->data);
		edge=ptr->link;
		ptr=ptr->nextvertex;
		while(edge!=NULL){							//Traverse each edge connected to the vertex
			printf("%d  ",edge->data);
			edge=edge->nextedge;
		}printf("\n");
		printf("------------------------\n");
		
	}
	
}


//Function to delete an edge

void delete_edge(struct node_vertex *ptr,int x,int y){      //x-Source vertex    y-Destination vertex
	while(ptr->data!=x){                       //Locate the first vertex(source of the edge)
		ptr=ptr->nextvertex;
	}
	struct node_edge *preptr=ptr->link;
	struct node_edge *postptr;
	if(preptr->data==y){                       //If the destination vertex is the first edge of the source vertex
		ptr->link=NULL;
	}else{
		while(preptr->data!=y){				   //else locate the destination vertex
			postptr=preptr;
			preptr=preptr->nextedge;
		}
		postptr->nextedge=preptr->nextedge;	
	}
	
	free(preptr);	
}


//Function to mark the initial status of all nodes before Traversal (init=0)

void initiate(struct node_vertex *ptr){   //ptr-Pointer to the starting vertex(Head)
	struct node_edge *edge;
	while(ptr!=NULL){                    //Traverse through the whole graph and updates the status of each vertex to 0
		ptr->status=0;
		edge=ptr->link;
		ptr=ptr->nextvertex;
		while(edge!=NULL){
			edge->status=0;
			edge=edge->nextedge;
		}	
	}
}


//Function to mark the identified nodes in Traversal (state=1)

int statechange(int m){							  // m- Starting vertex
	struct node_vertex *ptr=head;                 //Once a node is discovered in the graph, updates the status
	while(ptr!=NULL){							  // of that node to 1
		struct node_edge *ptr2=ptr->link;
		while(ptr2!=NULL){
			if(ptr2->data==m){
				ptr2->status=1;
			}
			ptr2=ptr2->nextedge;
		}
		ptr=ptr->nextvertex;
	}	
}


//Breadth First Traversal

void BFT(int n){						// n-Starting vertex
	initiate(head);                    //Marks all nodes as undiscovered(status=0)
	int a;
	struct node_vertex *ptr=head;
	struct node_edge *ptr2;
	while(ptr->data!=n){			   //Locates the starting vertex
		ptr=ptr->nextvertex;
	}
	ptr->status=1;						//Update the status of the starting vertex as 1
	enqueue(ptr->data);					//Add the starting vertex to the queue
	statechange(ptr->data);				//Locate each vertex with the starting vertex value and update its status to 1
	ptr2=ptr->link;
	while(ptr2!=NULL){					//Enqueue all the vertices connected to the starting vertex and
		ptr2->status=1;					//Update their status to 1 in the whole graph
		enqueue(ptr2->data);
		statechange(ptr2->data);
		ptr2=ptr2->nextedge;
	}
	printf("\n\nBFT: %d ",dequeue());			//Dequeue and print the starting vertex
	while(!isempty()){
		a=dequeue();							//While the queue is not empty dequeue each element
		printf("%d ",a);						//print its value
		struct node_vertex *ptr3=head;
		while(ptr3->data!=a){					//Locate all the edges starting from that vertex and if they
			ptr3=ptr3->nextvertex;				//are undiscovered(status=0),Enqueue the vertex value and
		}										//change the status of all the vertices with that value to 1
		struct node_edge *ptr4=ptr3->link;
		while(ptr4!=NULL){
			if(ptr4->status==0){
				enqueue(ptr4->data);
				statechange(ptr4->data);
			}
			ptr4=ptr4->nextedge;
			
		}
	}
	printf("\n\n");	
}


//Function to delete a vertex

void delete_vertex(int n){					 //n-vertex to be deleted
	struct node_vertex *ptr=head;
	struct node_vertex *ptr2;
	if(ptr->data==n){					     //If the vertex to be deleted id the first vertex
		head=ptr->nextvertex;
		
	}else{									 //Else search for the vertex and make the previous vertex point to the 
		while(ptr->data!=n){				 //vertex after the vertex to be removed
			ptr2=ptr;
			ptr=ptr->nextvertex;
		}
		ptr2->nextvertex=ptr->nextvertex;
	}
	free(ptr);								 //Free the vertex from memory
	struct node_vertex *ptr3=head;				
	while(ptr3!=NULL){									//Locate all the vertices connected to the deleted node
		struct node_edge *ptr4=ptr3->link;				//delete and free them from memory
		struct node_edge *ptr5;
		if(ptr4->data==n){
			ptr3->link=ptr4->nextedge;
			free(ptr4);
		}else{
			while(ptr4!=NULL){
				if(ptr4->data==n){
					ptr5->nextedge=ptr4->nextedge;
					free(ptr4);
				}
				ptr5=ptr4;
				ptr4=ptr4->nextedge;	
			}
		}
		ptr3=ptr3->nextvertex;
	}	
}


//Depth First Traversal

void DFT(int a){						//a-Starting vertex
	initiate(head);
	struct node_vertex *ptr=head;
	struct node_edge *preptr;
	while(ptr->data!=a){				//Locate the starting vertex
		ptr=ptr->nextvertex;
	}
	statechange(ptr->data);				//Mark the starting vertex as discovered(status=1)
	preptr=ptr->link;
	printf("DFT: ");
	while(preptr!=NULL){				//Traverese through the vertices connected to the starting vertex 
		if(preptr->status==0){			// and if the vereteces are not discovered call visit function
			visit(preptr->data);
		}
		preptr=preptr->nextedge;
	}
	printf("%d ",a);
}

// Recursive function for DFT

int visit(int b){
	statechange(b);							//Mark the vertex as discovered(status=1)
	struct node_vertex *ptr=head;
	while(ptr->data!=b){
		ptr=ptr->nextvertex;
	}
	struct node_edge *preptr=ptr->link;
	while(preptr!=NULL){					//Traverese through all the vertices connected to the current vertex
		if(preptr->status==0){				// and if a vertex is undiscovered call the visit function with the 
			visit(preptr->data);			// value of that vertex
		}
		preptr=preptr->nextedge;
	}
	printf("%d ",b);
}

//Main function


int main(){
	int x,y,v,i,j,s,q,k,l,m,n,o;
	printf("\n                    *******Graph Implementation Using*******\n                                  Adjacency List\n\n\n");
	printf("     >>>>>Let's Create a Graph<<<<<\n\n");
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	for(i=1;i<=v;i++){
		head=create_v(head,i);
	}
	while(1){
		printf("Enter edge v1--->v2(enter 0 0 to end): ");
		scanf("%d %d",&x,&y);
		if(x==0||y==0){
			break;
		}else{
			create_e(head,x,y);
		}

	}
	printf("\nGraph Created Successfully\n\n");
				

	while(1){
		printf("\n\n\n     >>>>>Select Option<<<<<\n");
		printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
		printf("\n|1.Display Graph              |\n|2.Add New vertex             |\n|3.Add New Edge               |\n|4.Delete Edge                |\n|5.Delete Vertex              |\n|6.Breadth First Traversal    |\n|7.Depth First Traversal      |\n|8.Exit                       |\n");
		printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
		printf("\n\nEnter Selection: ");
		scanf("%d",&s);
	
	
		switch(s){
			case 1:
				printf("\n\n");
				print(head);
				printf("\n\n");
				break;
			case 2:
				printf("\nEnter Value: ");
				scanf("%d",&q);
				head=create_v(head,q);
				break;
			case 3:
				while(1){
					printf("Enter New Edge v1--->v2(enter 0 0 to end): ");
					scanf("%d %d",&x,&y);
					if(x==0||y==0){
						break;
					}else{
						create_e(head,x,y);
					}
		
				}
				break;
				
			case 4:
				printf("Enter Edge to be removed(v v): \n");
				scanf("%d %d",&k,&l);
				delete_edge(head,k,l);
				printf("Edge removed Successfully\n");
				break;
			case 5:
				printf("Enter vertex to be removed: ");
				scanf("%d",&n);
				delete_vertex(n);
				printf("Vertex removed Successfully\n");
				break;
			case 6:
				printf("Enter starting Vertex: ");
				scanf("%d",&m);
				BFT(m);
				break;
			case 7:
				printf("Enter starting Vertex: ");
				scanf("%d",&o);
				DFT(o);
				printf("\n\n");
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Invalid Selection");
				break;
		}
	}
	
	

	
}