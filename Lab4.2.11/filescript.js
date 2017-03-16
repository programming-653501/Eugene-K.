var dataArr = new Array(26);

for (var i = 0; i < 26; i++) {
	dataArr[i] = new Array;
	dataArr[i][0] = 0;
	dataArr[i][1] = {label: String.fromCharCode(i + 97)};
}
	
for (var i = 0; i < content.length; i++) {
	console.log(content[i]);
	if (content[i] >= 'a' && content[i] <= 'z') {
		dataArr[content[i].charCodeAt(0) - 97][0]++;
	}
}

$(document).ready(function () {
  $('#awesome-graph').tufteBar({
    data: dataArr,
	barLabel:  function(index) { 
      return $.tufteBar.formatNumber(this[0]) 
    },
	axisLabel: function(index) { return this[1].label },
	color: function(index) { 
      return ['#E57536', '#82293B'][index % 2] 
    }
  });
});


