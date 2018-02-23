$(window).on('resize', function() {
    if ($(window).width() < 400) { // TODO Refactor
        $("#menu").removeClass("pure-menu-horizontal");
        $("#menu").hide();
        $("#toggle-menu").show();
    } else {
        $("#menu").addClass("pure-menu-horizontal");
        $("#menu").show();
        $("#toggle-menu").hide();
    }
});

$(document).ready(function() {
    $("#toggle-menu").click(function() {
        $("#menu").toggle();
    });
});
