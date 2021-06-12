/* See LICENSE file for copyright and license details. */ /* appearance */ static const unsigned int borderpx  = 1;        /* border pixel of windows */ static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "JetBrainsMono:size=9" };
static const char col_black[]       = "#000000";
static const char col_gray1[]       = "#202020";
static const char col_gray2[]       = "#404040";
static const char col_gray3[]       = "#b0b0b0";
static const char col_gray4[]       = "#c0c0c0";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_black,  col_gray4  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "firefox",  NULL,       NULL,       1 << 1,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "alacritty", NULL };

static Key keys[] = {
	/* modifier         key                function         argument */
	{ MODKEY,           XK_w,              spawn,           SHCMD("firefox") },
	{ MODKEY,           XK_t,              spawn,           SHCMD("tx") },
	{ MODKEY,           XK_b,              spawn,           SHCMD("status") },
	{ MODKEY,           XK_c,              spawn,           SHCMD("color") },
	{ MODKEY,           XK_s,              spawn,           SHCMD("screenshot") },
	{ MODKEY,           XK_d,              spawn,           SHCMD("dmenu_run") },
	{ MODKEY,           XK_e,              spawn,           SHCMD("clipmenu") },
	{ MODKEY,           XK_p,              spawn,           SHCMD("passmenu") },
	{ MODKEY|ShiftMask, XK_p,              spawn,           SHCMD("pwgen") },
	{ MODKEY,           XK_7,              spawn,           SHCMD("pamixer --allow-boost -d 5") },
	{ MODKEY,           XK_8,              spawn,           SHCMD("pamixer --allow-boost -i 5") },
	{ MODKEY|ShiftMask, XK_7,              spawn,           SHCMD("pamixer --allow-boost -d 15") },
	{ MODKEY|ShiftMask, XK_8,              spawn,           SHCMD("pamixer --allow-boost -i 15") },
	{ MODKEY|ShiftMask, XK_m,              spawn,           SHCMD("pamixer -t") },
	{ MODKEY,           XK_9,              spawn,           SHCMD("xbacklight -dec 1") },
	{ MODKEY,           XK_0,              spawn,           SHCMD("xbacklight -inc 1") },
	{ MODKEY|ShiftMask, XK_9,              spawn,           SHCMD("xbacklight -dec 15") },
	{ MODKEY|ShiftMask, XK_0,              spawn,           SHCMD("xbacklight -inc 15") },
	{ MODKEY,           XK_Return,         spawn,           {.v = termcmd } },
	{ MODKEY,           XK_j,              focusstack,      {.i = +1 } },
	{ MODKEY,           XK_k,              focusstack,      {.i = -1 } },
	{ MODKEY,           XK_bracketright,   incnmaster,      {.i = +1 } },
	{ MODKEY,           XK_bracketleft,    incnmaster,      {.i = -1 } },
	{ MODKEY,           XK_h,              setmfact,        {.f = -0.05} },
	{ MODKEY,           XK_l,              setmfact,        {.f = +0.05} },
	{ MODKEY,           XK_space,          zoom,            {0} },
	{ MODKEY,           XK_Tab,            view,            {0} },
	{ MODKEY,           XK_q,              killclient,      {0} },
	{ MODKEY,           XK_n,              setlayout,       {.v = &layouts[0]} },
	{ MODKEY,           XK_m,              setlayout,       {.v = &layouts[1]} },
	{ MODKEY|ShiftMask, XK_space,          togglefloating,  {0} },
	{ MODKEY,           XK_0,              view,            {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,              tag,             {.ui = ~0 } },
	TAGKEYS(            XK_1,                               0)
	TAGKEYS(            XK_2,                               1)
	TAGKEYS(            XK_3,                               2)
	{ MODKEY|ShiftMask, XK_q,              quit,            {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

