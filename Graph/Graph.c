#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct node_edge{
	int data;
	struct node_edge *nextedge;
	int status;
};
struct node_vertex{
	int data;
	struct node_edge *link;
	struct node_vertex *nextvertex;
	int status;
};
struct node_vertex *head=NULL;


//Function to create a vertex

struct node_vertex *create_v(struct node_vertex* ptr,int m){
	if(ptr==NULL){
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

struct node_edge *create_e(struct node_vertex *ptr,int x,int y){
	while(ptr->data!=x){
		ptr=ptr->nextvertex;
	}
	struct node_edge *edge=ptr->link;
	if(edge!=NULL){
		while(edge->nextedge!=NULL){
			edge=edge->nextedge;
		}
		struct node_edge *newedge;
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));
		newedge->data=y;
		newedge->nextedge=NULL;
		edge->nextedge=newedge;	
	}else{
		struct node_edge *newedge;
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));
		newedge->data=y;
		newedge->nextedge=NULL;
		ptr->link=newedge;
	}	
}


//Function to print the graph

void print(struct node_vertex *ptr){
	struct node_edge *edge;
	printf("Vertex\t        Edge\n\n");
	while(ptr!=NULL){
		printf("%d\t\t",ptr->data);
		edge=ptr->link;
		ptr=ptr->nextvertex;
		while(edge!=NULL){
			printf("%d  ",edge->data);
			edge=edge->nextedge;
		}printf("\n");
		printf("------------------------\n");
		
	}
	
}


//Function to delete an edge

void delete_edge(struct node_vertex *ptr,int x,int y){
	while(ptr->data!=x){
		ptr=ptr->nextvertex;
	}
	struct node_edge *preptr=ptr->link;
	struct node_edge *postptr;
	if(preptr->data==y){
		ptr->link=NULL;
	}else{
		while(preptr->data!=y){
			postptr=preptr;
			preptr=preptr->nextedge;
		}
		postptr->nextedge=preptr->nextedge;	
	}
	
	free(preptr);	
}


//Function to mark the initial status of all nodes before Traversal (init=0)

void initiate(struct node_vertex *ptr){
	struct node_edge *edge;
	while(ptr!=NULL){
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

int statechange(int m){
	struct node_vertex *ptr=head;
	while(ptr!=NULL){
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

void BFT(int n){
	initiate(head);
	int a;
	struct node_vertex *ptr=head;
	struct node_edge *ptr2;
	while(ptr->data!=n){
		ptr=ptr->nextvertex;
	}
	ptr->status=1;
	enqueue(ptr->data);
	statechange(ptr->data);
	ptr2=ptr->link;
	while(ptr2!=NULL){
		ptr2->status=1;
		enqueue(ptr2->data);
		statechange(ptr2->data);
		ptr2=ptr2->nextedge;
	}
	printf("\n\nBFT: %d ",dequeue());
	while(!isempty()){
		a=dequeue();
		printf("%d ",a);
		struct node_vertex *ptr3=head;
		while(ptr3->data!=a){
			ptr3=ptr3->nextvertex;
		}
		struct node_edge *ptr4=ptr3->link;
		while(ptr4!=NULL){
			if(ptr4->status==0){
				enqueue(ptr4->data);
			}
			ptr4=ptr4->nextedge;
			statechange(ptr4->data);
		}
	}
	printf("\n\n");	
}


//Function to delete a vertex

void delete_vertex(int n){
	struct node_vertex *ptr=head;
	struct node_vertex *ptr2;
	if(ptr->data==n){
		head=ptr->nextvertex;
		
	}else{
		while(ptr->data!=n){
			ptr2=ptr;
			ptr=ptr->nextvertex;
		}
		ptr2->nextvertex=ptr->nextvertex;
	}
	free(ptr);
	struct node_vertex *ptr3=head;
	while(ptr3!=NULL){
		struct node_edge *ptr4=ptr3->link;
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

void DFT(int a){
	initiate(head);
	struct node_vertex *ptr=head;
	struct node_edge *preptr;
	while(ptr->data!=a){
		ptr=ptr->nextvertex;
	}
	statechange(ptr->data);
	preptr=ptr->link;
	printf("DFT: ");
	while(preptr!=NULL){
		if(preptr->status==0){
			visit(preptr->data);
		}
		preptr=preptr->nextedge;
	}
	printf("%d ",a);
}

// Recursive function for DFT

int visit(int b){
	statechange(b);
	struct node_vertex *ptr=head;
	while(ptr->data!=b){
		ptr=ptr->nextvertex;
	}
	struct node_edge *preptr=ptr->link;
	while(preptr!=NULL){
		if(preptr->status==0){
			visit(preptr->data);
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
					printf("Enter New Edge v1 v2(enter 0 0 to end): ");
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