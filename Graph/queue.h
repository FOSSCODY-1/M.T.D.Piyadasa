#define size 20
int queue[size],front,rear;
front=-1;
rear=-1;
void enqueue(int a){
	if(rear==size-1){
		printf("Queue is full\n");
	}else{
		if(front==-1){
			front=0;
		}
		rear++;
		queue[rear]=a;
	}
}

int dequeue(){
	int n=queue[front];
	if(front==-1){
		printf("Empty queue\n");
	}
	else{
		front++;
		if(front>rear){
			front=rear=-1;
		}
	}
	return n;
	
}
int isempty(){
	if(rear==-1||front>rear){
		return 1;
	}else{
		return 0;
	}
	
	
	
	
}
