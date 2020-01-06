var Player = require('../models/player');
var Board = require('../models/board');



exports.render_board = function(req, res, next) {

var query = Board.find({})
query.sort({coordinates: 1});
query.exec(function(err, data) {
	if(err) {
		console.log(err);
		return
	}
	if(data.length == 0) {
		console.log("Pituus on nolla...");
		return
	}

	var cell_list = create_cell_list(data);

	res.render('index', {title: 'Testing testing...', cells: cell_list});

	})


};


exports.reset_board = function(req, res, next) {

var query = {};
var valueUpdate = {$set: {value: 0}};

Board.updateMany(query
, valueUpdate
, function (err, result) {

    if (err) {

        console.log("update document error");

    } else {

	console.log("Game board has been reset.");
    }

});

res.redirect('/');
};






function create_cell_list(db_list) {
		
	var cell_list = [];
	var n = db_list.length;
	var i;
	for (i = 0; i < n; i++) {
		if (db_list[i].value == 0) {
			cell_list.push("");
		} else if (db_list[i].value == 1) {
			cell_list.push("X");
		} else if (db_list[i].value == -1){
			cell_list.push("O");
		}
	}



return cell_list;

}






