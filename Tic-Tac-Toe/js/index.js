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
		console.log("WIN");
	if(box4.innerHTML !== "" && box4.innerHTML===box5.innerHTML && box4.innerHTML === box6.innerHTML)
		console.log("WIN");
	if(box7.innerHTML !== "" && box7.innerHTML===box8.innerHTML && box7.innerHTML === box9.innerHTML)
		console.log("WIN");
	if(box1.innerHTML !== "" && box1.innerHTML===box4.innerHTML && box1.innerHTML === box7.innerHTML)
		console.log("WIN");
	if(box2.innerHTML !== "" && box2.innerHTML===box5.innerHTML && box2.innerHTML === box8.innerHTML)
		console.log("WIN");
	if(box3.innerHTML !== "" && box3.innerHTML===box6.innerHTML && box3.innerHTML === box9.innerHTML)
		console.log("WIN");
	if(box1.innerHTML !== "" && box1.innerHTML===box5.innerHTML && box1.innerHTML === box9.innerHTML)
		console.log("WIN");
	if(box7.innerHTML !== "" && box7.innerHTML===box5.innerHTML && box7.innerHTML === box3.innerHTML)
		console.log("WIN");

}