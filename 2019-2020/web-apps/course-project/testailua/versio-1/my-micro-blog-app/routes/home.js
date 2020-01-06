var express = require('express');
var router = express.Router();

// Require controller modules.
var test_user_controller = require('../controllers/testUserController');
var blog_post_controller = require('../controllers/blogPostController');


/* GET home page. */
router.get( '/', test_user_controller.count_users_and_posts);


/*Get most recent posts  and search form*/
router.get('/posts', blog_post_controller.recent_posts);

/*Search and display posts by other users*/
router.post('/posts', blog_post_controller.search_posts);


router.get('/login', function(req, res, next) {
	res.render('login');
});


router.get('/register', function(req, res, next) {
	res.render('register');
});

router.post('/login', test_user_controller.check_log_in);

router.post('/register', test_user_controller.check_registration);


module.exports = router;
