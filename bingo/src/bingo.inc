<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/looe.dtd">
<html lang="ja">
<head>
<title>☆BINGO☆</title>
</head>
<body>
<center>
<h1>☆BINGO☆</h1>
<div class="check" style="display: none">
<table border="1">
$TABLE
</table>
</div>
<div class="game">
<p id="imgSrc">
$IMGSRC
</p>
</div>
<a id="startButton" href="javascript:void(0)"><img src="../buttons/start.gif"></a>
<a id="stopButton" href="javascript:void(0)"><img src="../buttons/stop.gif"></a>
<a id="topButton" href="javascript:void(0)"><img src="../buttons/top.gif"></a>
<a id="backButton" href="javascript:void(0)" style="display: none"><img src="../buttons/back.gif"></a>
<div class="game">
<p id="imgTitle">
<h3>
$TITLE
</h3>
</p>
</div>
</center>
<script type="text/javascript" src="./js/yui-min.js"></script>
<script type="text/javascript">
<!--
// Init Global
var YUI         = window.YUI,
    currentNum  = 0,
$LISTMAX,
    rouletteFlg = 1,    // 0:start / 1:stop
    topFlg      = 1,    // 0:top / 1:game
    indexList   = new Array;

YUI().use('event', 'node', function(Y) {
    Y.on('domready', function() {
        // Init List
        for (var i=0; i<listMax; i++) {
            indexList[i] = i;
        }

        // Start Roulette
        var start = function(e) {
            // doing roulette
            if (!rouletteFlg | !topFlg) {
                return;
            }

            // No List
            if (!listMax) {
                alert('Finish');
                return;
            }

            // Set Start Flag
            rouletteFlg = 0;
        };

        // Show Image
        var doRoulette = function() {
            // exit case
            if (rouletteFlg || !listMax) {
                return;
            }

            // roulette
            var rnd = Math.floor(Math.random() * listMax);
            Y.one('#image' + currentNum).setStyle('display', 'none');
            Y.one('#image' + indexList[rnd]).setStyle('display', '');
            Y.one('#title' + currentNum).setStyle('display', 'none');
            Y.one('#title' + indexList[rnd]).setStyle('display', '');
            currentNum = indexList[rnd];
        };

        // Stop Roulette
        var stop = function(e) {
            // not doing roulette
            if (rouletteFlg) {
                return;
            }

            // Set Stop Flag
            rouletteFlg = 1;

            // Set Rnd
            var rnd = Math.floor(Math.random() * listMax),
                str = '',
                i;

            // Set Image and Name
            Y.one('#image' + currentNum).setStyle('display', 'none');
            Y.one('#image' + indexList[rnd]).setStyle('display', '');
            Y.one('#title' + currentNum).setStyle('display', 'none');
            Y.one('#title' + indexList[rnd]).setStyle('display', '');
            currentNum = indexList[rnd];

            // Set Cell's Color
            Y.one('#cell' + indexList[rnd]).setStyle('backgroundColor', '#D0A9F5');

            /*
            // CheckList and Rnd
            for (i=0; i<listMax; i++) {
                str += indexList[i] + ',';
            }
            alert('rnd : ' + indexList[rnd] + "\nlist : " + str);
            */

            // Shift Rnd
            for (i=rnd; i<listMax; i++) {
                indexList[i] = indexList[i+1];
            }

            listMax--;
        };

        // Show Check Table
        var check = function(e) {
            // doing roulette
            if (!rouletteFlg) {
                return;
            }

            // Change Display
            Y.all('.check').setStyle('display', '');
            Y.all('.game').setStyle('display', 'none');
            Y.one('#topButton').setStyle('display', 'none');
            Y.one('#backButton').setStyle('display', '');
            topFlg = 0;
        };

        // Show Game
        var back = function(e) {
            // doing roulette
            if (!rouletteFlg) {
                return;
            }
            // Change Display
            Y.all('.check').setStyle('display', 'none');
            Y.all('.game').setStyle('display', '');
            Y.one('#topButton').setStyle('display', '');
            Y.one('#backButton').setStyle('display', 'none');
            topFlg = 1;
        };

        // Call func setInterval
        setInterval(doRoulette, 10);

        // Event Listener
        Y.on('click', start, '#startButton', this);
        Y.on('click', stop, '#stopButton', this);
        Y.on('click', check, '#topButton', this);
        Y.on('click', back, '#backButton', this);
    });
});
-->
</script>
</body>
</html>
