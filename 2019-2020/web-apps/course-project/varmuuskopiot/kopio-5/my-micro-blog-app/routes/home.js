var express = require('express');
var router = express.Router();

// Require controller modules.
var blog_post_controller = require('../controllers/blogPostController');
var user_controller = require('../controllers/userController');


/* GET home page. */
router.get( '/', user_controller.count_users_and_posts);


/*Get most recent posts  and search form*/
router.get('/posts', blog_post_controller.recent_posts);


/*Search and display posts by other users*/
router.post('/posts', blog_post_controller.search_posts);


router.get('/create_post', function(req, res, next) {
	res.render('create_post');
});


router.post('/create_post', blog_post_controller.create_new_post);

router.get('/register', function(req, res) {
	res.render('register');
});

router.post('/register', user_controller.register_new_user);


module.exports = router;
