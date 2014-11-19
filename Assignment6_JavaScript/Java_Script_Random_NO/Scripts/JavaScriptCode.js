
        $(document).ready(function () {

            var color = "";
           

            
           
            $("td").mouseover(function () {
                $(this).css({ "border-collapse": "collapse" });
                $(this).css({ "border": "thick dotted #eee" });
                
            });

            $("td").mouseout(function () {
                $("td").css({ "border": "5px solid #eee"});
            });

            $(":radio").click(function () {
                color=$(this).val();
            });

            $("#Reset").click(function () {
                $("td").css({"background-color":"#ccc"});
		
            });

            $("#Randomize").click(function () {
                boxes = new Array(9);
                

                $("td").each(function (i) {
                    boxes[i] = new Array(2);
                    boxes[i][0] = $(this).html();
                    boxes[i][1]=$(this).css("background-color");

                });

                boxes.sort(function () { return 0.5 - Math.random() });

                $("td").each(function (i) {
                    $(this).html(boxes[i][0]);
                    $(this).css({ "background-color": boxes[i][1] });

                });
            });


            $("td").click(function () {
                var currentColor=$(this).css("background-color");
                if (color == "") {
                    alert("Please select a color before clicking boxes");
                }
                else
                    if (color == currentColor)
                    {
                        alert("Already applied "+color+" color");
                    }
                    else
                    {
                        $(this).css({ "background-color": color });
                       
                    }
            });
        });

