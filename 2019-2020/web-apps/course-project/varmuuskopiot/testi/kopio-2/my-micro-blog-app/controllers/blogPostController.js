const validator = require('express-validator');
const bcrypt = require('bcrypt');
var BlogPost = require('../models/blog_post');


exports.count_posts = function(req, res) {
	BlogPost.countDocuments({}, function(err, count){
		res.render('home', {blog_post_count: count, error: err});
	});
};




exports.recent_posts = function(req, res) {
	var query = BlogPost.find({})
	query.limit(10);
	query.sort({post_date: -1});
	query.exec(function(err, results) {
		res.render('posts', {title: '10 most recent posts', data: results});
	});
};


exports.search_posts =[
	validator.body('username', 'Invalid username. Username must be at least 3 characters long.').isLength({ min: 3 }).trim(),
	validator.sanitizeBody('username').escape(),

	(req, res, next) => {
		const errors = validator.validationResult(req);
		if(!errors.isEmpty()) {
			console.log("Data from form is not valid.");
		} else {
			console.log("Data from form is valid.")
			var query = BlogPost.find({'username': req.body.username})
			query.sort({post_date: -1});
			query.exec(function(err, posts) {
				if (posts.length < 1) {
					console.log("No posts found.");
					res.render('posts', {title: 'No posts found.'});
				} else {
					console.log("Posts found.");
					var title_text = "Posts from user: " + req.body.username;
					res.render('posts', {title: title_text, data: posts});
				}
			});
		}
	}
];



