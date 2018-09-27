//Main function of the game

function game(){	                                             //Selects all the boxes and marks each box with the 
	for(var i=0; i < boxes.length ;i++){						 //respective mark "X" or "Y" depending on the previous 
		boxes[i].onclick=function(){							 //player's mark
			if(this.innerHTML!=="X" && this.innerHTML!=="O"){
				if (value%2===0) {
					console.log(value);
					this.innerHTML = "X";
					turn.innerHTML="Player 2's turn";
					winner();									//Calls winner function each time a player marks a box
					value++;									// to see if he he is the winner
					if(value===9){								//Instructor outputs draw if all the boxes are filled 
						turn.innerHTML="DRAW";					//without a winner
					}
				}else{
					console.log(value);
					this.innerHTML="O";
					turn.innerHTML="Player 1's turn";
					winner();
					value++;
				}
			}
		};
	}
}

//Function to check if the necessary conditions are satisfied for a player to win


function winner(){
	var box1=document.getElementById("box1"),
		box2=document.getElementById("box2"),
		box3=document.getElementById("box3"),
		box4=document.getElementById("box4"),
		box5=document.getElementById("box5"),
		box6=document.getElementById("box6"),
		box7=document.getElementById("box7"),
		box8=document.getElementById("box8"),
		box9=document.getElementById("box9");

	if(box1.innerHTML !== "" && box1.innerHTML===box2.innerHTML && box1.innerHTML === box3.innerHTML)
		selection(box1,box2,box3);
	if(box4.innerHTML !== "" && box4.innerHTML===box5.innerHTML && box4.innerHTML === box6.innerHTML)
		selection(box4,box5,box6);
	if(box7.innerHTML !== "" && box7.innerHTML===box8.innerHTML && box7.innerHTML === box9.innerHTML)
		selection(box7,box8,box9);
	if(box1.innerHTML !== "" && box1.innerHTML===box4.innerHTML && box1.innerHTML === box7.innerHTML)
		selection(box1,box4,box7);
	if(box2.innerHTML !== "" && box2.innerHTML===box5.innerHTML && box2.innerHTML === box8.innerHTML)
		selection(box2,box5,box8);
	if(box3.innerHTML !== "" && box3.innerHTML===box6.innerHTML && box3.innerHTML === box9.innerHTML)
		selection(box3,box6,box9);
	if(box1.innerHTML !== "" && box1.innerHTML===box5.innerHTML && box1.innerHTML === box9.innerHTML)
		selection(box1,box5,box9);
	if(box7.innerHTML !== "" && box7.innerHTML===box5.innerHTML && box7.innerHTML === box3.innerHTML)
		selection(box7,box5,box3);

}

//Function to highlight the winnig boxes and output the player who won

function selection(b1,b2,b3){
	b1.style.background = "white";
	b2.style.background = "white";
	b3.style.background = "white";
	if(b1.innerHTML==="X"){
		turn.innerHTML="Player 1 won";
		value++;
		var boxes = document.querySelectorAll("#main div");
		for(var i=0; i < boxes.length ;i++){
			boxes[i].onclick=function(){
				if(this.innerHTML!==" X"&&this.innerHTML!=="O"){
					this.innerHTML=" ";
				}
			}

		}
	}else{
		turn.innerHTML="Player 2 won";
		value++;
		var boxes = document.querySelectorAll("#main div");
		for(var i=0; i < boxes.length ;i++){
			boxes[i].onclick=function(){
				if(this.innerHTML!==" X"&&this.innerHTML!=="O"){
					this.innerHTML=" ";
				}
			}

		}
	}
}

