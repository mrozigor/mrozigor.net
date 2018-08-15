displayMenuCorrectly = function () {
    if ($(window).width() < 400) { // TODO Refactor
        $(".navigation__menu").addClass("navigation__menu--vertical");
        $(".navigation__menu").hide();
        $(".navigation__toggle-menu-button").show();
    } else {
        $(".navigation__menu").removeClass("navigation__menu--vertical");
        $(".navigation__menu").show();
        $(".navigation__toggle-menu-button").hide();
    }
}

$(window).on('resize', displayMenuCorrectly);

$(document).ready(function() {
    displayMenuCorrectly();

    $(".navigation__toggle-menu-button").click(function() {
        $(".navigation__menu").toggle();
    });
});
