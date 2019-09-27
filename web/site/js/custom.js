$(function() {
$("[data-scroll").on("click", function(event) {
        event.preventDefault(); //відміняєм станрадартне поведінку ссилки

        var blockId = $(this).data('scroll'); // id блока на який будем скролити
        var blockOffset = $(blockId).offset().top; // позиція цього елементу від верху сторінки

        $("#nav a").removeClass("active"); // ставим дизайн для активної ссилки
        $(this).addClass("active");


        $("html, body").animate({ // сам скролл
            scrollTop: blockOffset
        }, 500); //скільки мс


    });
});