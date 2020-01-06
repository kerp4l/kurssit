const validator = require('express-validator');
const bcrypt = require('bcrypt');
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


exports.register_new_user = [

	validator.body('username', 'Invalid username. Username can only contain letters and numbers.').isAlphanumeric(),
	validator.body('username', 'Invalid username. Username must be at least 3 characters long.').isLength({ min: 3 }).trim(),
	validator.body('username', 'Invalid username. Maximum length for username is 15 characters.').isLength({ max: 15 }).trim(),
	validator.sanitizeBody('username').escape(),
	validator.body('password1', 'Invalid password. Password can only contain letters and numbers.').isAlphanumeric(),
	validator.body('password1', 'Invalid password. Password must be at least 5 characters long.').isLength({ min: 5 }).trim(),
	validator.body('password1', 'Invalid password. Maximum length for password is 15 characters.').isLength({ max: 15 }).trim(),
	validator.sanitizeBody('password1').escape(),
	validator.body('password2', 'Invalid password. Password can only contain letters and numbers.').isAlphanumeric(),
	validator.body('password2', 'Invalid password. Password must be at least 5 characters long.').isLength({ min: 5 }).trim(),
	validator.body('password2', 'Invalid password. Maximum length for password is 15 characters.').isLength({ max: 15 }).trim(),
	validator.sanitizeBody('password2').escape(),



	(req, res, next) => {
		const errors = validator.validationResult(req);

		if (!errors.isEmpty()) {
			res.render('register', {errors: errors.array()});
		} else {
			User.findOne({'username': req.body.username})
			.exec( function(err, found_user) {
				if(found_user) {
					console.log("Löytyi!");
					res.render('register',{error_msg: 'That username is already taken.'});
				} else {
					console.log("Käyttäjää ei löytynyt!");
					res.render('create_post');
				}
			});
		}
	}

];




