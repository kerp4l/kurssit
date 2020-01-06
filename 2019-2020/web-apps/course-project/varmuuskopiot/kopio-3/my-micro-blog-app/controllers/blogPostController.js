const validator = require('express-validator');
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


exports.search_posts = [
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


exports.create_new_post = [

	validator.body('username', 'Invalid username. Username must be at least 3 characters long.').isLength({ min: 3 }).trim(),
	validator.body('username', 'Invalid username. Maximum length for username is 15 characters.').isLength({ max: 15 }).trim(),
	validator.sanitizeBody('username').escape(),
	validator.body('post_text', 'Your post is empty. please write something to post.').isLength({ min: 1 }).trim(),
	validator.body('post_text', 'Your post is too long. Maximum length for post is 250 characters.').isLength({ max: 10 }).trim(),
	validator.sanitizeBody('post_text').escape(),
	validator.body('username', 'Invalid username. Username can only contain letters and numbers.').isAlphanumeric(),

	(req, res, next) => {
		const errors = validator.validationResult(req);
		if (!errors.isEmpty()) {
			res.render('create_post', {errors: errors.array()});
		} else {
		console.log("ID: " + req.body.username);
		console.log("Viesti: " + req.body.post_text);
		res.render('create_post');

		}
	}

];




