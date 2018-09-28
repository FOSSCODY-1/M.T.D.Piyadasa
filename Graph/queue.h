#define size 200
int queue[size],front,rear;						//Front-Front end of the queue, Rear-Rear end of the queue
front=-1;
rear=-1;

//Function to Insert into the queue

void enqueue(int a){
	if(rear==size-1){    						//Checks if the queue is Full
		printf("Queue is full\n");
	}else{
		if(front==-1){						
			front=0;
		}
		rear++;									//Enqueues to the rear end
		queue[rear]=a;
	}
}

//Function to dequeue from the queue

int dequeue(){
	int n=queue[front];
	if(front==-1){								//Checks if the queue is empty
		printf("Empty queue\n");
	}
	else{
		front++;								//Dequeues from the front end
		if(front>rear){
			front=rear=-1;
		}
	}
	return n;
	
}

//Function to check if the queue is empty

int isempty(){
	if(rear==-1||front>rear){
		return 1;
	}else{
		return 0;
	}
	
	
	
	
}
