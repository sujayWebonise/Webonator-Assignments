var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
ctx.beginPath();
ctx.moveTo(250, 0);
ctx.lineTo(250, 500);
ctx.stroke();

ctx.moveTo(0, 250);
ctx.lineTo(500, 250);
ctx.stroke();

function equation_regx()
{
	var equation_value=document.getElementById('equation').value;	
	var equation_regx = new RegExp("y=([0-9]+)x([+|-])([0-9]+)");
	var array = equation_regx.exec(equation_value);
	var inbound_value=document.getElementById('inbound').value;
	if(inbound_value == '')alert("Inbound is empty");
	var outbound_value=document.getElementById('outbound').value;
	if(outbound_value == '')alert("outbound is empty");
	var steps_value=document.getElementById('step').value;
	if(steps_value == '')alert("steps is empty");
	if(array)
	{
		alert("equation matched");
		var m=array[1];
		var o=array[2];
		var b=array[3];
		var m=parseInt(m);
		var b=parseInt(b);
		if(o=='+')
		{
			var y1=m*inbound_value+b;
			var y2=m*outbound_value+b;
		}
		else
		{
			var y1=m*inbound_value-b;
			var y2=m*outbound_value-b;
		}
	ctx.translate(250,250);
	document.getElementById('y1').value=y1;
	document.getElementById('y2').value=y2;
	var difference=inbound_value-outbound_value;
	if(y1>0)
	{
		ctx.moveTo(inbound_value, -y1);
		if(y2>0)
		{	
			ctx.lineTo(outbound_value, -y2);
		}
		else
		{
			ctx.lineTo(outbound_value, -y2);
		}	
		ctx.stroke();
	
	}

	else
	{
		ctx.moveTo(inbound_value, -y1);
		if(y2>0)
		{	
			ctx.lineTo(outbound_value, -y2);
		}
		else
		{
			ctx.lineTo(outbound_value, -y2);
		}	
			ctx.stroke();
	}
	}
	else
	{
		alert("Please enter vallied equation Whith format y=mx+c");
	}
}


