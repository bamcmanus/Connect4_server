console.log("here")

var player = 'black';
alert('Black starts!')
$('td').click(function () {
    var myClass = $(this).attr("class");
    var result = findLowest(myClass);
    
});

function findLowest(myClass) {
    $($('.' + myClass).get().reverse()).each(function() {
        if (!$(this).hasClass("red") && !$(this).hasClass("black")) {
            if (player === 'black'){
               $(this).addClass('black');
               player = 'red';
               alert(player + ' player is up!')
            }
            else if (player === 'red'){
               $(this).addClass('red'); 
               player = 'black';
               alert(player + ' player is up!')
            }
            return false;
        }
    });

}