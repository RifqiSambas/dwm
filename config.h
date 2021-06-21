static const unsigned int borderpx  = 1; 
static const unsigned int snap      = 32;
static const char *fonts[]          = { "IBMPlexMono:size=13" };
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
static const char *tags[] = { "1", "2"};

static const Rule rules[] = {
	/* class        instance    title   tags mask     isfloating   monitor */
	{ "firefox",    NULL,       NULL,   1 << 1,       0,           -1 },
	{ "mpv",        NULL,       NULL,   1 << 1,       0,           -1 },
	{ "Zathura",    NULL,       NULL,   1 << 1,       0,           -1 },
	{ "St",			NULL,       NULL,   1 << 0,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50;
static const int nmaster     = 1;   
static const int resizehints = 1;   

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,    view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,    toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,    tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,    toggletag,  {.ui = 1 << TAG} },
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Key keys[] = {
	/* modifier         key         function    argument */
	TAGKEYS(            XK_1,                   0)
	TAGKEYS(            XK_2,                   1)
	{ MODKEY,           XK_grave,   spawn,      SHCMD("menucode") },
	{ MODKEY,           XK_w,       spawn,      SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask, XK_w,       spawn,      SHCMD("$BROWSER --private-window") },
	{ MODKEY,           XK_Return,  spawn,      SHCMD("tx") },
	{ MODKEY,           XK_b,       spawn,      SHCMD("status") },
	{ MODKEY,           XK_c,       spawn,      SHCMD("color") },
	{ MODKEY,           XK_s,       spawn,      SHCMD("screenshot") },
	{ MODKEY,           XK_d,       spawn,      SHCMD("dmenu_run") },
	{ MODKEY|ShiftMask, XK_Return,  spawn,      SHCMD("tmux new-session -d; pkill st; st -e tmux a") },
	{ MODKEY,           XK_e,       spawn,      SHCMD("clipmenu") },
	{ MODKEY,           XK_p,       spawn,      SHCMD("passmenu") },
	{ MODKEY|ShiftMask, XK_p,       spawn,      SHCMD("pwgen") },
	{ MODKEY,           XK_7,       spawn,      SHCMD("amixer set 'Master' 5%-") },
	{ MODKEY,           XK_8,       spawn,      SHCMD("amixer set 'Master' 5%+") },
	{ MODKEY|ShiftMask, XK_7,       spawn,      SHCMD("amixer set 'Master' 15%-") },
	{ MODKEY|ShiftMask, XK_8,       spawn,      SHCMD("amixer set 'Master' 15%+") },
	{ MODKEY|ShiftMask, XK_m,       spawn,      SHCMD("amixer set 'Master' toggle") },
	{ MODKEY|ShiftMask, XK_n,       spawn,      SHCMD("amixer set 'Capture' toggle") },
	{ MODKEY,           XK_9,       spawn,      SHCMD("backlight -dec 1") },
	{ MODKEY,           XK_0,       spawn,      SHCMD("xbacklight -inc 1") },
	{ MODKEY|ShiftMask, XK_9,       spawn,      SHCMD("xbacklight -dec 15") },
	{ MODKEY|ShiftMask, XK_0,       spawn,      SHCMD("xbacklight -inc 15") },
	{ MODKEY,           XK_j,       focusstack, {.i = +1 } },
	{ MODKEY,           XK_k,       focusstack, {.i = -1 } },
	{ MODKEY,           XK_f,       incnmaster, {.i = +1 } },
	{ MODKEY,           XK_g,       incnmaster, {.i = -1 } },
	{ MODKEY,           XK_h,       setmfact,   {.f = -0.05} },
	{ MODKEY,           XK_l,       setmfact,   {.f = +0.05} },
	{ MODKEY,           XK_space,   zoom,       {0} },
	{ MODKEY,           XK_Tab,     view,       {0} },
	{ MODKEY,           XK_q,       killclient, {0} },
	{ MODKEY,           XK_n,       setlayout,  {.v = &layouts[0]} },
	{ MODKEY,           XK_m,       setlayout,  {.v = &layouts[1]} },
	{ MODKEY|ShiftMask, XK_space,   tofloat,    {0} },
	{ MODKEY,           XK_3,       view,       {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_3,       tag,        {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_q,       spawn,      SHCMD("tmux kill-server") },
};

static Button buttons[] = {
	/* click        event mask  button     function     argument */
	{ ClkWinTitle,  0,          Button2,   zoom,        {0} },
	{ ClkClientWin, MODKEY,     Button1,   movemouse,   {0} },
	{ ClkClientWin, MODKEY,     Button2,   tofloat,     {0} },
	{ ClkClientWin, MODKEY,     Button3,   resizemouse, {0} },
};

