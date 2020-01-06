var User = require('../models/user');
var BlogPost = require('../models/blog_post');

var async = require('async');

exports.count_users_and_posts  = function(req, res) {

	    async.parallel({
		user_count: function(cb) {
			User.countDocuments({}, cb);
		},
		post_count: function(cb) {
			BlogPost.countDocuments({}, cb);
		}
	}, function(err, results) {
		res.render('home', {error: err, data: results});
	});
};


exports.search_get = function(req, res) {
	res.render('search');
};



exports.check_log_in = function(req, res) {
	res.redirect('/home');
};


exports.check_registration = function(req, res){
	res.redirect('/home');
};





