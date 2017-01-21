/*GESTION DE POLITICA DE COOKIES */
function getCookie(c_name) {            
	var c_value = document.cookie; // en c_value ponemos las cookies

	var c_start = c_value.indexOf(" " + c_name + "="); // busca un nombre de cookie

	if (c_start == -1) {
		c_start = c_value.indexOf(c_name + "=");
	}

	// Si esta vacia en c_start se pone c_name

	if (c_start == -1) {
		c_value = null;
	} else {
		c_start = c_value.indexOf("=", c_start) + 1;
		var c_end = c_value.indexOf(";", c_start);
		if (c_end == -1) {
			c_end = c_value.length;
		}
		c_value = unescape(c_value.substring(c_start, c_end));
	}
	return c_value;
}

function setCookie(c_name, value, exdays) {
	var exdate = new Date();
	exdate.setDate(exdate.getDate() + exdays);
	var c_value = escape(value) + ((exdays == null) ? "" : "; expires=" + exdate.toUTCString());
	c_value += "; path=/";
	document.cookie = c_name + "=" + c_value;
}

function PonerCookie() {
	setCookie('aviso', '1', 365);
	document.getElementById("privacy-policy").style.display = "none";
}

