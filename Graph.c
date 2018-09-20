#include<stdio.h>
#include<stdlib.h>

struct node_edge{
	int data;
	struct node_edge *nextedge;
};
struct node_vertex{
	int data;
	struct node_edge *link;
	struct node_vertex *nextvertex;
};
struct node_vertex *head=NULL;

struct node_vertex *create_v(struct node_vertex* ptr,int m){
	if(ptr==NULL){
//		printf("testing...");
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
struct node_edge *create_e(struct node_vertex *ptr,int x,int y){
//	printf("wawawa");
	while(ptr->data!=x){
		ptr=ptr->nextvertex;
	}
	struct node_edge *edge=ptr->link;
	if(edge!=NULL){
//		printf("eyow");
		while(edge->nextedge!=NULL){
			edge=edge->nextedge;
		}
		struct node_edge *newedge;
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));
		newedge->data=y;
		newedge->nextedge=NULL;
		edge->nextedge=newedge;	
	}else{
//		printf("meowww");
		struct node_edge *newedge;
		newedge=(struct node_edge*)malloc(sizeof(struct node_edge));
		newedge->data=y;
		newedge->nextedge=NULL;
		ptr->link=newedge;
	}	
}
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

int main(){
	int x,y,v,i,j,s,q,k,l;
	while(1){
		printf("1.Create Graph\n2.Display Graph\n3.Add New vertex\n4.Add New Edge\n5.Delete Edge\n6.Exit\n");
		printf("\n\nEnter Selection: ");
		scanf("%d",&s);
	
	
		switch(s){
			case 1:
				printf("Enter the number of vertices: ");
				scanf("%d",&v);
				for(i=1;i<=v;i++){
					head=create_v(head,i);
				}
				while(1){
					printf("Enter edge v1 v2(enter 0 0 to end): ");
					scanf("%d %d",&x,&y);
					if(x==0||y==0){
						break;
					}else{
						create_e(head,x,y);
					}
		
				}
				printf("Graph Created Successfully\n\n");
				break;
			case 2:
				printf("\n\n");
				print(head);
				printf("\n\n");
				break;
			case 3:
				printf("\nEnter Value: ");
				scanf("%d",&q);
				head=create_v(head,q);
				break;
			case 4:
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
				
			case 5:
				printf("Enter Edge to be removed(v v): ");
				scanf("%d %d",&k,&l);
				delete_edge(head,k,l);
				break;
			case 6:
				exit(0);
		}
	}
	
	

	
}



















