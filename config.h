/* See LICENSE file for copyright and license details. */
#ifdef CONFINIT

/* terminal */
#define TERM "st"
#define TERMCLASS "st-256color"

/* border */
static const unsigned int borderpx             = 7;  /* border pixel of windows */
static const unsigned int innerborderpx        = 3;  /* inner border pixel of windows */
static const unsigned int innerborderoffsetpx  = 2;  /* distance between inner border and window */

/* layout settings */
static const int pertag            = 1;    /* 1 means remember layout, mfact and nmaster per tag */
static const int resettag          = 1;    /* 1 means reset layout, mfact and nmaster when tag is emptied */
static const unsigned int gappx    = 15;   /* gaps between windows */
static const float mfact           = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster           = 1;    /* number of clients in master area */
static const int nmasterbias       = 1;    /* reduce nmaster if masters are removed when nmaster > nmasterbias; <0 to disable */
static const unsigned int stairpx  = 75;   /* depth of the stairs layout */
static const int stairsdirection   = 1;    /* alignment of the stairs layout; 0: left-aligned, 1: right-aligned */
static const int stairssamesize    = 0;    /* 1 means shrink all the staired windows to the same size */

/* bar and systray */
static const int showbar      = 1;    /* 0 means no bar */
static const int topbar       = 1;    /* 0 means bottom bar */
static const int showsystray  = 1;    /* 0 means no systray */
static const int statusmonnum = -1;   /* monitor number to show status and systray on; <0 means follow selected monitor */
static const float cindfact   = 0.1;  /* size of client indicators */

/* other settings */
static const unsigned int snap            = 32;  /* snap pixel */
static const int lockfullscreen           = 0;   /* 1 will force focus on the fullscreen window */
static const int swallowfloating          = 0;   /* 1 means swallow floating windows as well */
static const int resizehints              = 1;   /* 1 means respect size hints in tiled resizals */
static const unsigned char xkblayout      = 0;   /* the default keyboard layout number; 0 is the main layout */
static const int noautofocus              = 1;   /* the default noautofocus setting; see the noautofocus rule below */
static const unsigned int killdoublepress = 500; /* killclient double press time in milliseconds; set 0 to disable  */

/* fonts */
static const char *fonts[] = {
    "Signika Negative:size=13",
    ":lang=fa:spacing=mono:size=13",
    "Symbols Nerd Font:size=10",
};

/* colors */
static const char normfg[]    = "#666666";
static const char bgclr[]     = "#181b1c";
static const char borderbg[]  = "#000000";
static const char textclr[]   = "#bfbfbf";
static const char *colors[SchemeLast][ClrLast] = {
    /*                    FG           BG      Border         BorderBG */
    [SchemeNorm]      = { normfg,      bgclr,  "#333333",     borderbg }, /* colors of normal (unselected) items, tags, and window borders */
    [SchemeSel]       = { "#bfbfbf",   bgclr,  "#ffffff",     borderbg }, /* colors of selected items, tags and and window borders */
    [SchemeTitle]     = { textclr,     bgclr,  NULL,          NULL     }, /* fg and bg color of the window title area in the bar */
    [SchemeUrg]       = { NULL,        NULL,   "#ff0000",     borderbg }, /* border color of urgent windows */
};

/* colors that can be used by the statusbar */
static const char *statuscolors[] = { "#333333", textclr };

/* tags */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#else /* CONFINIT */

/* layout array. first entry is default. */
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },
    { "[M]",      monocle },
    { "[S]",      stairs },
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* hint for rules
 *
 * completefullscreen:
 *   1 means make the window cover the entire monitor (even the bar) when
 *   it's fullscreen.
 *
 * noautofocus:
 *   1 means don't focus the window initially,
 *   0 means default behavior (autofocus).
 *
 * nojitter:
 *   some clients jump around every time their focue changes because they send
 *   ConfigureRequest events with incorrect coordinates.
 *   by setting nojitter to 1, the x and y of the ConfigureRequest of the client
 *   will be ignored, preventing it from dictating it's own window position.
 *
 * xprop(1):
 *    WM_CLASS(STRING) = instance, class
 *    WM_NAME(STRING) = title
 *
 * flt : isfloating
 * cfs : completefullscreen
 * naf : noautofocus
 * nsl : noswallow
 * ist : isterminal
 * njt : nojitter
 * tag : tagmask
 * mon : monitor
 */
static const Rule rules[] = {
    /* class, instance, title,                 flt cfs naf nsl ist njt tag mon  */
    { "TelegramDesktop", NULL, NULL,            0,  0,  0,  0,  0,  0,  0, -1 },
    { "TelegramDesktop", NULL, "Media viewer",  1,  1,  0,  0,  0,  0,  0, -1 },
    { "Qalculate", NULL, NULL,                  1,  0,  0,  0,  0,  0,  0, -1 },
    { "Droidcam", NULL, NULL,                   1,  0,  0,  0,  0,  0,  0, -1 },
    { ".exe", NULL, NULL,                       0,  0,  1,  0,  0,  0,  0, -1 },
    { "Steam", NULL, NULL,                      0,  0,  1,  0,  0,  1,  0, -1 },
    { "firefox", NULL, NULL,                    0,  0,  0,  0,  0,  0,  0, -1 },
    { "firefox", NULL, "Picture-in-Picture",    0,  1,  0,  0,  0,  0,  0, -1 },
    { "chromium", NULL, NULL,                   0,  0,  0,  0,  0,  0,  0, -1 },
    { "tabbed", NULL, NULL,                     0,  0,  0,  0,  0,  0,  0, -1 },
    { "Sxiv", NULL, NULL,                       0,  1,  1,  0,  0,  0,  0, -1 },
    { "mpv", NULL, NULL,                        0,  1,  1,  0,  0,  0,  0, -1 },
    { TERMCLASS, NULL, NULL,                    0,  0,  0,  0,  1,  0,  0, -1 },
    { NULL, NULL, "Event Tester",               0,  0,  0,  1,  0,  0,  0, -1 },
};

/* hint for attachdirection
 *
 * attach:
 *   the default behavior; new clients go in the master area.
 *
 * attachabove:
 *   make new clients attach above the selected client,
 *   instead of always becoming the new master. this behavior is known from xmonad.
 *
 * attachaside:
 *   make new clients get attached and focused in the stacking area,
 *   instead of always becoming the new master. it's basically an attachabove modification.
 *
 * attachbelow:
 *   make new clients attach below the selected client,
 *   instead of always becoming the new master. inspired heavily by attachabove.
 *
 * attachbottom:
 *   new clients attach at the bottom of the stack instead of the top.
 *
 * attachtop:
 *   new client attaches below the last master/on top of the stack.
 *   behavior feels very intuitive as it doesn't disrupt existing masters,
 *   no matter the amount of them, it only pushes the clients in stack down.
 *   in case of nmaster = 1 feels like attachaside.
 */
static void (*attachdirection)(Client *) = attachbelow;

/* ============== */
/* = Key Macros = */
/* ============== */

/* key definitions */
#define Mod           Mod4Mask
#define Shift         ShiftMask
#define Ctrl          ControlMask
#define Alt           Mod1Mask
#define ModShift      Mod|Shift
#define ModCtrl       Mod|Ctrl
#define ModAlt        Mod|Alt
#define ModCtrlShift  ModCtrl|Shift
#define ModAltShift   ModAlt|Shift
#define ModAltCtrl    ModAlt|Ctrl
#define ModCtrlAlt    ModAltCtrl
#define CtrlShift     Ctrl|Shift
#define AltCtrl       Alt|Ctrl
#define AltCtrlShift  AltCtrl|Shift

/* key pair definition */
#define K1(K1, K2) K1
#define K2(K1, K2) K2
#define PAIR(MOD, PAIR, FN, ARG1, ARG2) \
    { MOD, K1(PAIR), FN, ARG1 }, \
    { MOD, K2(PAIR), FN, ARG2 }

/* common key pairs */
#define PAIR_JK            XK_j, XK_k
#define PAIR_HL            XK_h, XK_l
#define PAIR_COMMAPERIOD   XK_comma, XK_period
#define PAIR_BRACKET       XK_bracketleft, XK_bracketright
#define PAIR_VOL           XF86XK_AudioLowerVolume,  XF86XK_AudioRaiseVolume
#define PAIR_BRIGHTNESS    XF86XK_MonBrightnessDown, XF86XK_MonBrightnessUp

#define TAGKEYS(KEY,TAG) \
    { Mod,              KEY,    view,           {.ui = 1 << TAG} }, \
    { ModCtrl,          KEY,    toggleview,     {.ui = 1 << TAG} }, \
    { ModShift,         KEY,    tag,            {.ui = 1 << TAG} }, \
    { ModCtrlShift,     KEY,    toggletag,      {.ui = 1 << TAG} }

/* ============ */
/* = Commands = */
/* ============ */

#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }
#define TUI(...)   { .v = (const char*[]){ TERM, "-e", __VA_ARGS__, NULL } }
#define SHCMD(CMD) { .v = (const char*[]){ "/bin/sh", "-c", CMD, NULL } }
#define SHTUI(CMD) { .v = (const char*[]){ TERM, "-e", "/bin/sh", "-c", CMD, NULL } }

#define VOL(dB) CMD("pactl", "set-sink-volume", "@DEFAULT_SINK@", #dB "dB")
#define MPCVOL(PERCENT) CMD("mpc", "volume", #PERCENT)
#define MUTE CMD("pamixer", "-t")
#define PACYCLE CMD("pacycle")

#define TOGGLE_MIC_MUTE \
    SHCMD("pacmd list-sources | grep -q 'muted: yes' && { " \
    "pactl list short sources | cut -f1 | xargs -I{} pacmd set-source-mute {} false && " \
    "notify-send ' Mic Enabled.' -u low -h string:x-canonical-private-synchronous:togglemicmute; : ;} || { " \
    "pactl list short sources | cut -f1 | xargs -I{} pacmd set-source-mute {} true && " \
    "notify-send ' Mic Muted.' -u low -h string:x-canonical-private-synchronous:togglemicmute; : ;}")

#define MEDIA_PLAYPAUSE \
    SHCMD("mpc pause & file=${XDG_RUNTIME_DIR:?}/playpause p=$(playerctl -a status " \
    "-f '{{playerInstance}}\t{{status}}' | grep -v '\\<mpd\\>' | grep Playing) && { " \
    "printf '%s\\n' \"$p\" >\"$file\"; playerctl -a pause; : ;} || " \
    "cut -f1 \"$file\" | xargs -rL1 playerctl play -p")

#define MEDIACMD(MPC_CMD, PLAYERCTL_CMD) \
    SHCMD("(mpc | grep -q '^\\[playing' && mpc " MPC_CMD ") & " \
    "playerctl -a status -f '{{playerInstance}}\t{{status}}' | " \
    "grep Playing | cut -f1 | xargs -rL1 playerctl " PLAYERCTL_CMD " -p")

#define MEDIA_NEXT MEDIACMD("next", "next")
#define MEDIA_PREV MEDIACMD("prev", "previous")
#define MEDIA_SEEK_FWD  MEDIACMD("seek +10", "position 10+")
#define MEDIA_SEEK_BACK MEDIACMD("seek -10", "position 10-")

/* change the brightness of internal and external monitors */
#define LIGHTINC(N) SHCMD("light -A " #N "; monbrightness raise " #N)
#define LIGHTDEC(N) SHCMD("light -U " #N "; monbrightness lower " #N)

/* other */
#define PIPEURL CMD("pipeurl", "--clipboard", "ask")
#define NOTIFYSONG SHCMD("notify-send -u low -h string:x-canonical-private-synchronous:notifysong Playing: \"$(mpc current)\"")
#define XMOUSELESS SHCMD("usv down unclutter; xmouseless; usv up unclutter")
#define SENDKEY(KEYUP, ...) CMD("xdotool", "keyup", KEYUP, "key", "--clearmodifiers", __VA_ARGS__)
#define TERMCWD SHCMD("cd \"$(xcwd)\" && " TERM)
#define LASTDL CMD("zsh", "-c", "termopen ~/Downloads/*(om[1])") /* open the last downloaded file */

/* copy the clipboard contents to all running Xephyr instances */
#define COPYTOXEPHYR \
    SHCMD("confirm=$(printf 'No\\nYes\\n' | dmenu -p 'Copy Clipboard to all Xephyr instances?' " \
    "-nb '#222222' -nf '#aaaaaa' -sb '#52161e'); [ \"$confirm\" != Yes ] && exit; " \
    "xclip -o -selection clipboard -t TARGETS | grep -q image/png && target=image/png || unset target; " \
    "for dpy in $(pgrep -ax Xephyr | grep -o ' :[0-9]\\+'); do " \
    "xclip -o -r -selection clipboard ${target:+-t $target} | " \
    "DISPLAY=$dpy xclip -selection clipboard ${target:+-t $target}; done")


/* binding logic:
 * - audio and music related bindings start with super+alt (ModAlt)
 * - most bindings that have a similar function only differ by a shift modifier */
static const Key keys[] = {
  /*  modifier          key                   function          argument */
    { Mod,              XK_q,                 spawn,            CMD("sysact") },
    { Mod,              XK_m,                 spawn,            CMD("manuals") },
    { Mod,              XK_p,                 spawn,            CMD("stuff", "-m") },
    { ModShift,         XK_p,                 spawn,            CMD("dmenu_run", "-p", "Programs") },
    { Mod,              XK_t,                 spawn,            CMD(TERM) },
    { ModShift,         XK_t,                 spawn,            TERMCWD },
    { Mod,              XK_b,                 spawn,            SHCMD("exec $BROWSER") },
    { Mod,              XK_g,                 spawn,            XMOUSELESS },
    { Mod,              XK_n,                 spawn,            CMD("dunstctl", "close") },
    { ModShift,         XK_n,                 spawn,            CMD("dunstctl", "action") },
    { ModCtrl,          XK_n,                 spawn,            CMD("dunstctl", "history-pop") },
    { Mod,              XK_v,                 spawn,            SHTUI("exec ${EDITOR:-nvim}") },
    { Mod,              XK_e,                 spawn,            CMD("loginctl", "lock-session") },
    { Mod,              XK_d,                 spawn,            TUI("dictfzf") },
    { Mod,              XK_x,                 spawn,            COPYTOXEPHYR },
    { ModShift,         XK_q,                 restart,          {0} },

PAIR( 0,                PAIR_VOL,             spawn,            VOL(-3), VOL(+3) ),
PAIR( ModAlt,           PAIR_JK,              spawn,            VOL(-3), VOL(+3) ),
PAIR( ModAltShift,      PAIR_JK,              spawn,            MPCVOL(-10), MPCVOL(+10) ),
    { ModAlt,           XK_m,                 spawn,            MUTE },
    { ModAltShift,      XK_m,                 spawn,            TOGGLE_MIC_MUTE },
    { ModCtrl,          XK_s,                 spawn,            PACYCLE },
    { 0,                XF86XK_AudioMute,     spawn,            MUTE },
    { 0,                XF86XK_AudioMicMute,  spawn,            TOGGLE_MIC_MUTE },

    { ModAltShift,      XK_p,                 spawn,            CMD("mpc", "toggle") },
    { ModAlt,           XK_p,                 spawn,            MEDIA_PLAYPAUSE },
PAIR( ModAlt,           PAIR_HL,              spawn,            MEDIA_SEEK_BACK, MEDIA_SEEK_FWD ),
PAIR( ModAltShift,      PAIR_HL,              spawn,            MEDIA_PREV,      MEDIA_NEXT     ),
    { ModAlt,           XK_n,                 spawn,            NOTIFYSONG },
    { 0,                XF86XK_AudioPlay,     spawn,            MEDIA_PLAYPAUSE },
    { 0,                XF86XK_AudioPrev,     spawn,            MEDIA_PREV },
    { 0,                XF86XK_AudioNext,     spawn,            MEDIA_NEXT },

PAIR( 0,                PAIR_BRIGHTNESS,      spawn,            LIGHTDEC(10), LIGHTINC(10) ),
PAIR( Shift,            PAIR_BRIGHTNESS,      spawn,            LIGHTDEC(1),  LIGHTINC(1)  ),
PAIR( Mod,              PAIR_BRACKET,         spawn,            LIGHTDEC(10), LIGHTINC(10) ),
PAIR( ModShift,         PAIR_BRACKET,         spawn,            LIGHTDEC(1),  LIGHTINC(1)  ),

    { Mod,              XK_r,                 spawn,            PIPEURL },
    { ModShift,         XK_r,                 spawn,            CMD("pipeurl", "history") },
    { Mod,              XK_y,                 spawn,            CMD("qrsend") },

PAIR( Mod,              PAIR_JK,              focusstack,       {.i = +1 },    {.i = -1 } ),
PAIR( ModShift,         PAIR_JK,              push,             {.i = +1 },    {.i = -1 } ),
PAIR( Mod,              PAIR_HL,              setmfact,         {.f = -0.05 }, {.f = +0.05 } ),
    { Mod,              XK_s,                 switchcol,        {0} },
    { Mod,              XK_space,             zoom,             {0} },
    { ModShift,         XK_space,             transfer,         {0} },
    { Mod,              XK_Tab,               view,             {0} },
    { ModShift,         XK_w,                 killclient,       {0} },
    { ModCtrl,          XK_b,                 togglebar,        {0} },
    { Mod,              XK_f,                 togglefullscreen, {0} },
    { Mod,              XK_semicolon,         setlayout,        {.lt = tile } },
    { ModShift,         XK_semicolon,         setlayout,        {.lt = stairs } },
    { ModCtrl,          XK_semicolon,         setlayout,        {.lt = monocle } },
PAIR( ModCtrl,          PAIR_JK,              incnmaster,       {.i = -1 }, {.i = +1 } ),
    { ModShift,         XK_f,                 togglefloating,   {0} },
    { Mod,              XK_0,                 view,             {.ui = ~0 } },
    { ModShift,         XK_0,                 tag,              {.ui = ~0 } },

PAIR( Mod,              PAIR_COMMAPERIOD,     viewmon,          {.i = +1 }, {.i = -1 } ),
PAIR( ModShift,         PAIR_COMMAPERIOD,     tagmon,           {.i = +1 }, {.i = -1 } ),
    { Mod,              XK_comma,             viewmon,          {.i = -1 } },
    { Mod,              XK_period,            viewmon,          {.i = +1 } },
    { ModShift,         XK_comma,             tagmon,           {.i = -1 } },
    { ModShift,         XK_period,            tagmon,           {.i = +1 } },

    TAGKEYS(XK_1, 0), TAGKEYS(XK_2, 1), TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3), TAGKEYS(XK_5, 4), TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6), TAGKEYS(XK_8, 7), TAGKEYS(XK_9, 8),
};

/* macro for defining scroll actions for when the cursor is on any window or the root window */
#define GLOBALSCROLL(MOD, FN, ARG_UP, ARG_DOWN) \
    { ClkRootWin,   MOD, Button4, FN, ARG_UP   }, \
    { ClkRootWin,   MOD, Button5, FN, ARG_DOWN }, \
    { ClkClientWin, MOD, Button4, FN, ARG_UP   }, \
    { ClkClientWin, MOD, Button5, FN, ARG_DOWN }

/* same as above, but for clicking instead of scrolling */
#define GLOBALCLICK(MOD, FN, ARG) \
    { ClkRootWin,   MOD, Button1, FN, ARG }, \
    { ClkClientWin, MOD, Button1, FN, ARG }

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click            modifier   key         function          argument */
    { ClkLtSymbol,      0,         Button1,    setlayout,        {0} },
    { ClkLtSymbol,      0,         Button2,    setlayout,        {.lt = tile } },
    { ClkLtSymbol,      0,         Button3,    setlayout,        {.lt = stairs } },
    { ClkWinTitle,      0,         Button1,    spawn,            PIPEURL },
    { ClkStatusText,    0,         Button2,    spawn,            CMD(TERM) },
    { ClkClientWin,     Mod,       Button1,    movemouse,        {0} },
    { ClkClientWin,     Mod,       Button2,    togglefloating,   {0} },
    { ClkClientWin,     Mod,       Button3,    resizemouse,      {0} },
    { ClkTagBar,        0,         Button1,    view,             {0} },
    { ClkTagBar,        0,         Button3,    toggleview,       {0} },
    { ClkTagBar,        Mod,       Button1,    tag,              {0} },
    { ClkTagBar,        Mod,       Button3,    toggletag,        {0} },
    { ClkStatusText,    0,         Button1,    spawn,            MUTE },
    { ClkStatusText,    0,         Button3,    spawn,            PACYCLE },
    { ClkStatusText,    0,         Button4,    spawn,            VOL(+3) },
    { ClkStatusText,    0,         Button5,    spawn,            VOL(-3) },
    GLOBALSCROLL(       Mod,                   focusstacktiled,  {.i = -1 },     {.i = +1 }    ), /* super+scroll:          change focus */
    GLOBALSCROLL(       ModShift,              push,             {.i = -1 },     {.i = +1 }    ), /* super+shift+scroll:    push the focused window */
    GLOBALSCROLL(       ModCtrl,               setmfact,         {.f = +0.05 },  {.f = -0.05 } ), /* super+control+scroll:  change mfact */
};

#endif /* CONFINIT */
// vim:expandtab
