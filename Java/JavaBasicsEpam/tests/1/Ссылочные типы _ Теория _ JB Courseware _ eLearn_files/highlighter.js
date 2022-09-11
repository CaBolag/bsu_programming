// <![CDATA[
var keywordsRegexp = /\b(abstract|continue|for|new|switch|assert|default|goto|package|synchronized|boolean|do|if|private|this|break|double|implements|protected|throw|byte|else|import|public|throws|case|enum|instanceof|return|transient|catch|extends|int|short|try|char|final|interface|static|void|class|finally|long|strictfp|volatile|const|float|native|super|while|var)(?=[\.\(\[\ ])/g;
var stringRegexp = /"(.*?)"/g;
var numberRegexp = /(?<=[\(\_\ ])[-+]?(\d+[.,]?\d*)(?=[\_\;\,\)\ ])/g;
var metaRegexp = /\@(\w+)/g;
var commentRegexp = /\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*\//g;
var inlineCommentRegexp = /(\/\/.*)/g;
var codeElements = document.querySelectorAll('.code-background code span');
codeElements.forEach(item => {
    if (!item.classList.length) {
        parsed(item.textContent, item);
    }
    if (item.classList.contains('comment-wrapper')) {
        var commentText = item.querySelector(".comment");
        var innerComment = commentText.querySelector(".comment-wrapper");
        if (!innerComment) {
            parsed(commentText.innerText, commentText);
        }
    }
});

function parsed(cont, parent) {
    var parsedStrings = cont.replace(stringRegexp, '<span class="string-highlight">$&</span>');
    parent.innerHTML = parsedStrings;
    var parsedNumbers = parsedStrings.replace(numberRegexp, '<span class="number-highlight">$&</span>');
    parent.innerHTML = parsedNumbers;
    var parsedMetas = parsedNumbers.replace(metaRegexp, '<span class="meta-highlight">$&</span>');
    parent.innerHTML = parsedMetas;
    var parsedComments = parsedMetas.replace(commentRegexp, '<span class="comment-highlight">$&</span>');
    parent.innerHTML = parsedComments;
    var parsedInlineComments = parsedComments.replace(inlineCommentRegexp, '<span class="comment-highlight">$&</span>');
    parent.innerHTML = parsedInlineComments;
    var parsedKeywords = parsedInlineComments.replace(keywordsRegexp, '<span class="keyword-highlight">$&</span>');
    parent.innerHTML = parsedKeywords;
}
// ]]>