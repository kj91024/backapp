
var marketCode = 'WE';
if (window.MarketCode) {
    marketCode = window.MarketCode;
}
var  GetCookieValue = function(cookieName) {
        var cookieArray = document.cookie.split(';');
        for (var index = 0; index < cookieArray.length ; index++) {
            var cookie = cookieArray[index];
            while (cookie.charAt(0) === ' ') {
                cookie = cookie.substring(1, cookie.length);
                if (cookie.indexOf(cookieName) === 0) {
                    return cookie.substring(cookieName.length + 1, cookie.length);
                }
            }
        }
        return '';
    }
function SetSessionCookie(c_name, value) {
    var c_value = value + ";path=/; expires=0";
    document.cookie = c_name + "=" + c_value;
}
var originalEntryUrlstr = 'OriginalEntryUrl';
var originalReferringUtlStr = 'OriginalReferringURl';
var errorPageName = 'errorPageName';
var MinervaInfoId = 'minervainfoid';
var OriginalMinervaInfoId = 'originalminervainfoid';
var originalEntryUrl = GetCookieValue(originalEntryUrlstr);
var OriginalReferringUrl = GetCookieValue(originalReferringUtlStr);
var ErrorPageName = GetCookieValue(errorPageName);
var trackingHost = '';

trackingHost = "www.ef.com";

if (!originalEntryUrl) {
    SetSessionCookie(originalEntryUrlstr, document.location);
}
if (!OriginalReferringUrl) {
    SetSessionCookie(originalReferringUtlStr, document.referrer);
}
var url = location.href;
var referrer = document.referrer;
var dtmPath = '';
var hostinfo = '&host=' + location.host;
var MinervaId = '';
var OriginalMinervaId = '';
//if (url.indexOf('localhost') > -1) {
//    dtmPath = '//assets.adobedtm.com/c3187449abe132496ab40b7e1d4045f9e2902ef5/satelliteLib-df8be426665be3b041d899e37a242266d6528dd7-staging.js';
//}
//else if (url.indexOf('myqa.ef') > -1) {
//    dtmPath = '//assets.adobedtm.com/c3187449abe132496ab40b7e1d4045f9e2902ef5/satelliteLib-df8be426665be3b041d899e37a242266d6528dd7-staging.js';
//}
//else {
//    dtmPath = '//assets.adobedtm.com/c3187449abe132496ab40b7e1d4045f9e2902ef5/satelliteLib-df8be426665be3b041d899e37a242266d6528dd7.js';

//}

var DTMDataLayer = {};
var s_account = '';
var efd = 0;

if (ErrorPageName != '') {
    window.CustomPageName = 'error:[' + ErrorPageName + ']';
    document.cookie = "errorPageName=;expires=Wed 01 Jan 1970;path=/";
}
if (window.CustomPageName) {
    DTMDataLayer.PageName = window.CustomPageName;
    setPageNameDependentProps(window.CustomPageName);
}
if (window.CustomWebsite) {
    DTMDataLayer.Website = window.CustomWebsite;
    setWebsiteDependentProps(window.CustomWebsite);
}

if (typeof (DTMDataLayer) != 'undefined' && typeof (DTMDataLayer.PageName) != 'undefined' && DTMDataLayer.PageName.match('^blog')) {
    efd = 1;
}


var xhr = new XMLHttpRequest();

xhr.open('GET', 'http://' + trackingHost +'/services/tracking/minerva?mc=' + marketCode + '&url=' + encodeURIComponent(url) + '&ref=' + encodeURIComponent(referrer) + '&tps=1&efd=' + efd + hostinfo, true);
xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
xhr.onload = function () {
    DTMDataLayer = JSON.parse(this.responseText);
    if (ErrorPageName != '') {
        window.CustomPageName = 'error:[' + ErrorPageName + ']';
        document.cookie = "errorPageName=;expires=Wed 01 Jan 1970;path=/";
    }
    if (window.CustomPageName) {
        DTMDataLayer.PageName = window.CustomPageName;
        setPageNameDependentProps(window.CustomPageName);
    }
    if (window.CustomWebsite) {
        DTMDataLayer.Website = window.CustomWebsite;
        setWebsiteDependentProps(window.CustomWebsite);
    }
    s_account = DTMDataLayer.OmnitureAccount;

    MinervaId = DTMDataLayer.MinervaId;
    OriginalMinervaId = DTMDataLayer.OriginalMinervaId;
    if (MinervaId == "" && OriginalMinervaId == "") {
        MinervaId = GetCookieValue(MinervaInfoId);
        OriginalMinervaId = GetCookieValue(OriginalMinervaInfoId);
    }
    /* var script = document.createElement('script');
    script.src = dtmPath;
   <script.onload = function () {
        _satellite.pageBottom();

    }
    document.head.appendChild(script);*/
    var tritonxhr = new XMLHttpRequest();
    tritonxhr.open('GET', 'http://' + trackingHost+'/services/tracking/triton?mc=' + marketCode +'&MinervaId=' + MinervaId + '&OriginalMinervaId=' + OriginalMinervaId + hostinfo, true);
    tritonxhr.withCredentials = true;
    tritonxhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    tritonxhr.send();
};
xhr.send();

function setPageNameDependentProps(customPageName) {
    var segments = customPageName.split(':');
    switch (segments.length) {
        case 2:
            DTMDataLayer.SiteSection = segments[0] + ':' + segments[1];
            break;
        case 3:
            DTMDataLayer.SiteSection = segments[0] + ':' + segments[1];
            DTMDataLayer.SubSection1 = segments[0] + ':' + segments[1] + ':' + segments[2];
            break;
        case 4:
        case 5:
            DTMDataLayer.SiteSection = segments[0] + ':' + segments[1];
            DTMDataLayer.SubSection1 = segments[0] + ':' + segments[1] + ':' + segments[2];
            DTMDataLayer.SubSection2 = segments[0] + ':' + segments[1] + ':' + segments[2] + ':' + segments[3];
            break;
        case 6:
        case 7:
            DTMDataLayer.SiteSection = segments[0] + ':' + segments[1];
            DTMDataLayer.SubSection1 = segments[0] + ':' + segments[1] + ':' + segments[2];
            DTMDataLayer.SubSection2 = segments[0] + ':' + segments[1] + ':' + segments[2] + ':' + segments[3];
            break;
        default:
            break;
    }
    DTMDataLayer.SiteHierarchy1 = DTMDataLayer.Website + ',' + getDeepestSiteSection();
    DTMDataLayer.SiteHierarchy2 = DTMDataLayer.MarketCode + "," + DTMDataLayer.Website + "," + getDeepestSiteSection();
    DTMDataLayer.SiteHierarchy = getSiteHierarchy();
    DTMDataLayer.Channel = DTMDataLayer.PageName.substring(0, DTMDataLayer.PageName.lastIndexOf(':'));
}
function setWebsiteDependentProps(customWebsite) {
    DTMDataLayer.SiteHierarchy1 = DTMDataLayer.Website + ',' + getDeepestSiteSection();
    DTMDataLayer.SiteHierarchy2 = DTMDataLayer.MarketCode + "," + DTMDataLayer.Website + "," + getDeepestSiteSection();
    DTMDataLayer.SiteHierarchy = getSiteHierarchy();
}
function getDeepestSiteSection() {
    if (DTMDataLayer.SubSection3) {
        return DTMDataLayer.SubSection3;
    }
    else if (DTMDataLayer.SubSection2) {
        return DTMDataLayer.SubSection2;
    }
    else if (DTMDataLayer.SubSection1) {
        return DTMDataLayer.SubSection1;
    }
    else if (DTMDataLayer.SiteSection) {
        return DTMDataLayer.SiteSection;
    }
    return null;
}

function getSiteHierarchy() {
    var deepestSiteSection = getDeepestSiteSection();
    if (deepestSiteSection) {
        return DTMDataLayer.Website + "," + DTMDataLayer.MarketCode + "," + deepestSiteSection;
    }
    return DTMDataLayer.Website + "," + DTMDataLayer.MarketCode;
}