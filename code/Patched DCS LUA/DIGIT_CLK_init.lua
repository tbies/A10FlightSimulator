dofile(LockOn_Options.common_script_path.."devices_defs.lua")

indicator_type = indicator_types.COMMON

------begin export  Above line should read indicator_type = indicator_types.COMMON

purposes                  = {render_purpose.GENERAL,
                                render_purpose.HUD_ONLY_VIEW,
                                render_purpose.SCREENSPACE_OUTSIDE_COCKPIT,
                                render_purpose.SCREENSPACE_INSIDE_COCKPIT}

local x_size         = 1
local y_size         = 1

function update_screenspace_diplacement(zoom_value)
    local default_width  = 0.5 * LockOn_Options.screen.height + (64 * zoom_value)
    if default_width > LockOn_Options.screen.height then
       default_width = LockOn_Options.screen.height
    end
    
    if default_width > 0.5 * LockOn_Options.screen.width then
       default_width = 0.5 * LockOn_Options.screen.width
    end
        
    local default_height = (y_size/x_size) * default_width
    local default_y      = LockOn_Options.screen.height - default_height
    local default_x      = LockOn_Options.screen.width  - default_width
   
    dedicated_viewport           = {default_x,default_y,default_width,default_height}
    dedicated_viewport_arcade = {default_x, 0        ,default_width,default_height}
end

update_screenspace_diplacement(0)    

function set_full_viewport_coverage(viewport)

   dedicated_viewport          = {viewport.x,
                                viewport.y,
                                viewport.width,
                                viewport.height}
   dedicated_viewport_arcade = dedicated_viewport
   purposes                  = {render_purpose.GENERAL,
                                render_purpose.HUD_ONLY_VIEW,
                                render_purpose.SCREENSPACE_OUTSIDE_COCKPIT,
                                render_purpose.SCREENSPACE_INSIDE_COCKPIT} -- set purposes to draw it always 
   render_target_always = false
end

-- try to find assigned viewport
local multimonitor_setup_name =  "Config/MonitorSetup/"..get_multimonitor_preset_name()..".lua"
local env = {}
      env.screen = LockOn_Options.screen
local f = loadfile(multimonitor_setup_name)
if      f     then
      setfenv(f,env)
      pcall(f)
      
      local vp = nil
	  ----------------------------------------Viewport Name
      vp = env.CLK_SCREEN
      ----------------------------------------Viewport Name
      if vp ~= nil then
         dbg_print("")
         set_full_viewport_coverage(vp)
      end       
end

------- end export

-------PAGE IDs-------
id_Page =
{
	PAGE_OFF		= 0,
	PAGE_MAIN		= 1
}

id_pagesubset =
{
	MAIN			= 0
}

page_subsets = {}
page_subsets[id_pagesubset.MAIN]	= LockOn_Options.script_path.."DigitalClock/Indicator/DIGIT_CLK_page.lua"

----------------------
pages = {}

pages[id_Page.PAGE_OFF]		= {}
pages[id_Page.PAGE_MAIN]	= {id_pagesubset.MAIN}

init_pageID		= id_Page.PAGE_OFF
use_parser		= false

--- master modes
A10C_DIGIT_CLK_OFF		   = 0 
A10C_DIGIT_CLK_MAIN        = 1 

------------------------------------
pages_by_mode                 = {}
clear_mode_table(pages_by_mode, 1, 0, 0)

function get_page_by_mode(master,L2,L3,L4)
	return get_page_by_mode_global(pages_by_mode,init_pageID,master,L2,L3,L4)
end

pages_by_mode[A10C_DIGIT_CLK_OFF][0][0][0]			  = id_Page.PAGE_OFF
pages_by_mode[A10C_DIGIT_CLK_MAIN][0][0][0]			  = id_Page.PAGE_MAIN
