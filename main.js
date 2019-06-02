//empty = 0
//black = 1
//red = 2

const ROWS = 6;
const COLS = 7;
var isOver = false;
var lastCol = 0;

const boardMap = Array.from({ length: ROWS }, () => (
    Array.from({ length: COLS }, () => 0)
));


var player = 'Black';
alert('Black starts!')
$('td').click(function () {
    var myClass = $(this).attr("class");
    makeMove(myClass);
    var result = checkWinner(lastCol);
    if (result === true) {
        gameOver();
    }

});

function makeMove(myClass) {
    $($('.' + myClass).get().reverse()).each(function (index) {
        if (!$(this).hasClass("red") && !$(this).hasClass("black")) {
            var colNum = parseInt(this.className.charAt(3), 10);

            if (player === 'Black') {
                $(this).addClass('black');
                player = 'Red';
                lastCol = colNum;
                boardMap[ROWS - 1 - index][colNum] = 1;
            }
            else if (player === 'Red') {
                $(this).addClass('red');
                player = 'Black';
                lastCol = colNum;
                boardMap[ROWS - 1 - index][colNum] = 2;
            }
            return false;
        }
    });
};

function checkWinner(lastCol) {
    if (is_winner_vert(lastCol)) {
        return true;
    }
    return false;
};

function is_winner_vert(lastCol) {
    let count = 0;
    for (let i = 0; i < ROWS; i++) {
        if (boardMap[i][lastCol] === 1 || boardMap[i][lastCol] === 2) {
            for (let j = i + 1; j < ROWS; j++) {
                if (boardMap[j][lastCol] == boardMap[i][lastCol]) {
                    count++;
                    console.log(boardMap[j][lastCol] + ' is first and ' + boardMap[i][lastCol] + ' is second and count is ' + count)
                }
                else {
                    break;
                }
            }
        }
    }
    if (count >= 4) {
        return true;
    }
    return false;
}
function gameOver() {
    if (player === 'Black') {
        alert('Game over, red wins!');
    }
    else {
        alert('Game over, black wins!');
    }
};

