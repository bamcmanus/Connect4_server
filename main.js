//empty = 0
//red = 1
//black = 2
const ROWS = 6;
const COLS = 7;

const boardMap = Array.from({ length:ROWS}, () => (
    Array.from( {length:COLS}, ()=> 0)
));
console.log(boardMap);
var player = 'black';
alert('Black starts!')
$('td').click(function () {
    var myClass = $(this).attr("class");
    var result = makeMove(myClass);   
    console.log(boardMap);
});

function makeMove(myClass) {
    $($('.' + myClass).get().reverse()).each(function(index) {
        if (!$(this).hasClass("red") && !$(this).hasClass("black")) {
            var colNum = parseInt(this.className.charAt(3), 10);
            if (player === 'black'){
               $(this).addClass('black');
               player = 'red';
               alert(player + ' player is up!' + ' index is ' + index + '. Colnum is ' + colNum)
               boardMap[ROWS - 1 - index][colNum] = 2;  
            }
            else if (player === 'red'){
               $(this).addClass('red'); 
               player = 'black';
               alert(player + ' player is up!' + ' index is ' + index)
               boardMap[ROWS - 1 - index][colNum] = 1;
            }
            return false;
        }
    });


}