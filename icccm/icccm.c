#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "xcb_icccm.h"
#include "xcb_atom.h"

xcb_get_property_cookie_t
xcb_get_text_property(xcb_connection_t *c,
                      xcb_window_t window,
                      xcb_atom_t property)
{
  return xcb_get_any_property(c, 0, window, property, UINT_MAX);
}

xcb_get_property_cookie_t
xcb_get_text_property_unchecked(xcb_connection_t *c,
                                xcb_window_t window,
                                xcb_atom_t property)
{
  return xcb_get_any_property_unchecked(c, 0, window, property, UINT_MAX);
}

uint8_t
xcb_get_text_property_reply(xcb_connection_t *c,
                            xcb_get_property_cookie_t cookie,
                            xcb_get_text_property_reply_t *prop,
                            xcb_generic_error_t **e)
{
  xcb_get_property_reply_t *reply = xcb_get_property_reply(c, cookie, e);
  if(!reply)
    return 0;

  prop->_reply = reply;
  prop->encoding = prop->_reply->type;
  prop->format = prop->_reply->format;
  prop->name_len = xcb_get_property_value_length(prop->_reply) * prop->format >> 3;
  prop->name = xcb_get_property_value(prop->_reply);

  return 1;
}

void xcb_get_text_property_reply_wipe(xcb_get_text_property_reply_t *prop)
{
  free(prop->_reply);
}

/* WM_NAME */

void
xcb_set_wm_name_checked (xcb_connection_t *c,
                         xcb_window_t      window,
                         xcb_atom_t        encoding,
                         uint32_t          name_len,
                         const char       *name)
{
	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, WM_NAME, encoding, 8, name_len, name);
}

void
xcb_set_wm_name (xcb_connection_t *c,
                 xcb_window_t      window,
                 xcb_atom_t        encoding,
                 uint32_t          name_len,
                 const char       *name)
{
	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, WM_NAME, encoding, 8, name_len, name);
}

xcb_get_property_cookie_t
xcb_get_wm_name(xcb_connection_t *c,
                xcb_window_t window)
{
  return xcb_get_text_property(c, window, WM_NAME);
}

xcb_get_property_cookie_t
xcb_get_wm_name_unchecked(xcb_connection_t *c,
                          xcb_window_t window)
{
  return xcb_get_text_property_unchecked(c, window, WM_NAME);
}

uint8_t
xcb_get_wm_name_reply(xcb_connection_t *c,
                      xcb_get_property_cookie_t cookie,
                      xcb_get_text_property_reply_t *prop,
                      xcb_generic_error_t **e)
{
  return xcb_get_text_property_reply(c, cookie, prop, e);
}

void
xcb_watch_wm_name (xcb_property_handlers_t        *prophs,
                   uint32_t                       long_len,
                   xcb_generic_property_handler_t handler,
                   void                          *data)
{
	xcb_set_property_handler(prophs, WM_NAME, long_len, handler, data);
}

/* WM_ICON_NAME */

void
xcb_set_wm_icon_name_checked (xcb_connection_t *c,
                              xcb_window_t      window,
                              xcb_atom_t        encoding,
                              uint32_t          name_len,
                              const char       *name)
{
	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, WM_ICON_NAME, encoding, 8, name_len, name);
}

void
xcb_set_wm_icon_name (xcb_connection_t *c,
                      xcb_window_t      window,
                      xcb_atom_t        encoding,
                      uint32_t          name_len,
                      const char       *name)
{
	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, WM_ICON_NAME, encoding, 8, name_len, name);
}

xcb_get_property_cookie_t
xcb_get_wm_icon_name(xcb_connection_t *c,
                     xcb_window_t window)
{
  return xcb_get_text_property(c, window, WM_ICON_NAME);
}

xcb_get_property_cookie_t
xcb_get_wm_icon_name_unchecked(xcb_connection_t *c,
                               xcb_window_t window)
{
  return xcb_get_text_property_unchecked(c, window, WM_ICON_NAME);
}

uint8_t
xcb_get_wm_icon_name_reply(xcb_connection_t *c,
                           xcb_get_property_cookie_t cookie,
                           xcb_get_text_property_reply_t *prop,
                           xcb_generic_error_t **e)
{
  return xcb_get_text_property_reply(c, cookie, prop, e);
}

void
xcb_watch_wm_icon_name (xcb_property_handlers_t        *prophs,
                        uint32_t                       long_len,
                        xcb_generic_property_handler_t handler,
                        void                          *data)
{
	xcb_set_property_handler(prophs, WM_ICON_NAME, long_len, handler, data);
}

/* WM_CLIENT_MACHINE */

void
xcb_set_wm_client_machine_checked (xcb_connection_t *c,
                                   xcb_window_t      window,
                                   xcb_atom_t        encoding,
                                   uint32_t          name_len,
                                   const char       *name)
{
	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, WM_CLIENT_MACHINE, encoding, 8, name_len, name);
}

void
xcb_set_wm_client_machine (xcb_connection_t *c,
                           xcb_window_t      window,
                           xcb_atom_t        encoding,
                           uint32_t          name_len,
                           const char       *name)
{
	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, WM_CLIENT_MACHINE, encoding, 8, name_len, name);
}

xcb_get_property_cookie_t
xcb_get_wm_client_machine(xcb_connection_t *c,
                          xcb_window_t window)
{
  return xcb_get_text_property(c, window, WM_CLIENT_MACHINE);
}

xcb_get_property_cookie_t
xcb_get_wm_client_machine_unchecked(xcb_connection_t *c,
                                    xcb_window_t window)
{
  return xcb_get_text_property_unchecked(c, window, WM_CLIENT_MACHINE);
}

uint8_t
xcb_get_wm_client_machine_reply(xcb_connection_t *c,
                                xcb_get_property_cookie_t cookie,
                                xcb_get_text_property_reply_t *prop,
                                xcb_generic_error_t **e)
{
  return xcb_get_text_property_reply(c, cookie, prop, e);
}

void
xcb_watch_wm_client_machine (xcb_property_handlers_t        *prophs,
                             uint32_t                       long_len,
                             xcb_generic_property_handler_t handler,
                             void                          *data)
{
	xcb_set_property_handler(prophs, WM_CLIENT_MACHINE, long_len, handler, data);
}

/* WM_TRANSIENT_FOR */

xcb_get_property_cookie_t
xcb_get_wm_transient_for(xcb_connection_t *c, xcb_window_t window)
{
  return xcb_get_property(c, 0, window, WM_TRANSIENT_FOR, WINDOW, 0, 1);
}

xcb_get_property_cookie_t
xcb_get_wm_transient_for_unchecked(xcb_connection_t *c, xcb_window_t window)
{
  return xcb_get_property_unchecked(c, 0, window, WM_TRANSIENT_FOR, WINDOW, 0, 1);
}

uint8_t
xcb_get_wm_transient_for_reply(xcb_connection_t *c,
                               xcb_get_property_cookie_t cookie,
                               xcb_window_t *prop,
                               xcb_generic_error_t **e)
{
  xcb_get_property_reply_t *reply = xcb_get_property_reply(c, cookie, e);

  if(!reply || reply->type != WINDOW || reply->format != 32 || !reply->length)
  {
    free(reply);
    return 0;
  }

  *prop = *((xcb_window_t *) xcb_get_property_value(reply));

  free(reply);
  return 1;
}

/* WM_SIZE_HINTS */

void
xcb_size_hints_set_position (xcb_size_hints_t *hints,
                             int               user_specified,
                             int32_t           x,
                             int32_t           y)
{
	hints->flags &= ~(XCB_SIZE_US_POSITION_HINT | XCB_SIZE_P_POSITION_HINT);
	if (user_specified)
		hints->flags |= XCB_SIZE_US_POSITION_HINT;
	else
		hints->flags |= XCB_SIZE_P_POSITION_HINT;
	hints->x = x;
	hints->y = y;
}

void
xcb_size_hints_set_size (xcb_size_hints_t *hints,
                         int               user_specified,
                         int32_t           width,
                         int32_t           height)
{
	hints->flags &= ~(XCB_SIZE_US_SIZE_HINT | XCB_SIZE_P_SIZE_HINT);
	if (user_specified)
		hints->flags |= XCB_SIZE_US_SIZE_HINT;
	else
		hints->flags |= XCB_SIZE_P_SIZE_HINT;
	hints->width = width;
	hints->height = height;
}

void
xcb_size_hints_set_min_size (xcb_size_hints_t *hints,
                             int32_t           min_width,
                             int32_t           min_height)
{
	hints->flags |= XCB_SIZE_P_MIN_SIZE_HINT;
	hints->min_width = min_width;
	hints->min_height = min_height;
}

void
xcb_size_hints_set_max_size (xcb_size_hints_t *hints,
                             int32_t           max_width,
                             int32_t           max_height)
{
	hints->flags |= XCB_SIZE_P_MAX_SIZE_HINT;
	hints->max_width = max_width;
	hints->max_height = max_height;
}

void
xcb_size_hints_set_resize_inc (xcb_size_hints_t *hints,
                               int32_t           width_inc,
                               int32_t           height_inc)
{
	hints->flags |= XCB_SIZE_P_RESIZE_INC_HINT;
	hints->width_inc = width_inc;
	hints->height_inc = height_inc;
}

void
xcb_size_hints_set_aspect (xcb_size_hints_t *hints,
                           int32_t           min_aspect_num,
                           int32_t           min_aspect_den,
                           int32_t           max_aspect_num,
                           int32_t           max_aspect_den)
{
	hints->flags |= XCB_SIZE_P_ASPECT_HINT;
	hints->min_aspect_num = min_aspect_num;
	hints->min_aspect_den = min_aspect_den;
	hints->max_aspect_num = max_aspect_num;
	hints->max_aspect_den = max_aspect_den;
}

void
xcb_size_hints_set_base_size (xcb_size_hints_t *hints,
                              int32_t           base_width,
                              int32_t           base_height)
{
	hints->flags |= XCB_SIZE_BASE_SIZE_HINT;
	hints->base_width = base_width;
	hints->base_height = base_height;
}

void
xcb_size_hints_set_win_gravity (xcb_size_hints_t *hints,
                                uint8_t           win_gravity)
{
	hints->flags |= XCB_SIZE_P_WIN_GRAVITY_HINT;
	hints->win_gravity = win_gravity;
}

void
xcb_set_wm_size_hints_checked (xcb_connection_t *c,
                               xcb_window_t      window,
                               xcb_atom_t        property,
                               xcb_size_hints_t *hints)
{
	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, property, WM_SIZE_HINTS, 32, sizeof(*hints) / 4, hints);
}

void
xcb_set_wm_size_hints (xcb_connection_t *c,
                       xcb_window_t      window,
                       xcb_atom_t        property,
                       xcb_size_hints_t *hints)
{
	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, property, WM_SIZE_HINTS, 32, sizeof(*hints) / 4, hints);
}

xcb_get_property_cookie_t
xcb_get_wm_size_hints(xcb_connection_t *c, xcb_window_t window,
                      xcb_atom_t property)
{
  /* NumPropSizeElements = 18 (ICCCM version 1). */
  return xcb_get_property(c, 0, window, property, WM_SIZE_HINTS, 0L, 18);
}

xcb_get_property_cookie_t
xcb_get_wm_size_hints_unchecked(xcb_connection_t *c, xcb_window_t window,
                                xcb_atom_t property)
{
  return xcb_get_property_unchecked(c, 0, window, property, WM_SIZE_HINTS,
                                    0L, 18);
}

uint8_t
xcb_get_wm_size_hints_reply(xcb_connection_t *c, xcb_get_property_cookie_t cookie,
                            xcb_size_hints_t *hints, xcb_generic_error_t **e)
{
  xcb_get_property_reply_t *reply = reply = xcb_get_property_reply(c, cookie, e);
  if(!reply)
    return 0;

  int length = xcb_get_property_value_length(reply);

  if (!(reply->type == WM_SIZE_HINTS &&
        (reply->format == 8  || reply->format == 16 ||
         reply->format == 32) &&
        /* OldNumPropSizeElements = 15 (pre-ICCCM) */
        length >= 15))
  {
    free(reply);
    return 0;
  }

  memcpy(hints, (xcb_size_hints_t *) xcb_get_property_value (reply),
         length * reply->format >> 3);

  hints->flags = (XCB_SIZE_US_POSITION_HINT | XCB_SIZE_US_SIZE_HINT |
                  XCB_SIZE_P_POSITION_HINT | XCB_SIZE_P_SIZE_HINT |
                  XCB_SIZE_P_MIN_SIZE_HINT | XCB_SIZE_P_MAX_SIZE_HINT |
                  XCB_SIZE_P_RESIZE_INC_HINT | XCB_SIZE_P_ASPECT_HINT);

  /* NumPropSizeElements = 18 (ICCCM version 1) */
  if(length >= 18)
    hints->flags |= (XCB_SIZE_BASE_SIZE_HINT | XCB_SIZE_P_WIN_GRAVITY_HINT);
  else
  {
    hints->base_width = 0;
    hints->base_height = 0;
    hints->win_gravity = 0;
  }

  free(reply);
  return 1;
}

/* WM_NORMAL_HINTS */

void
xcb_set_wm_normal_hints_checked (xcb_connection_t *c,
                                 xcb_window_t      window,
                                 xcb_size_hints_t *hints)
{
	xcb_set_wm_size_hints_checked(c, window, WM_NORMAL_HINTS, hints);
}

void
xcb_set_wm_normal_hints (xcb_connection_t *c,
                         xcb_window_t      window,
                         xcb_size_hints_t *hints)
{
	xcb_set_wm_size_hints(c, window, WM_NORMAL_HINTS, hints);
}

xcb_get_property_cookie_t
xcb_get_wm_normal_hints(xcb_connection_t *c, xcb_window_t window)
{
  return xcb_get_wm_size_hints(c, window, WM_NORMAL_HINTS);
}

xcb_get_property_cookie_t
xcb_get_wm_normal_hints_unchecked(xcb_connection_t *c, xcb_window_t window)
{
  return xcb_get_wm_size_hints_unchecked(c, window, WM_NORMAL_HINTS);
}

uint8_t
xcb_get_wm_normal_hints_reply(xcb_connection_t *c,
                              xcb_get_property_cookie_t cookie,
                              xcb_size_hints_t *hints,
                              xcb_generic_error_t **e)
{
  return xcb_get_wm_size_hints_reply(c, cookie, hints, e);
}

/* WM_HINTS */

uint32_t
xcb_wm_hints_get_urgency(xcb_wm_hints_t *hints)
{
       return (hints->flags & XCB_WM_X_URGENCY_HINT);
}

void
xcb_wm_hints_set_input(xcb_wm_hints_t *hints, uint8_t input)
{
        hints->input = input;
        hints->flags |= XCB_WM_INPUT_HINT;
}

void
xcb_wm_hints_set_iconic(xcb_wm_hints_t *hints)
{
        hints->initial_state = XCB_WM_ICONIC_STATE;
        hints->flags |= XCB_WM_STATE_HINT;
}

void
xcb_wm_hints_set_normal(xcb_wm_hints_t *hints)
{
        hints->initial_state = XCB_WM_NORMAL_STATE;
        hints->flags |= XCB_WM_STATE_HINT;
}

void
xcb_wm_hints_set_withdrawn(xcb_wm_hints_t *hints)
{
        hints->initial_state = XCB_WM_WITHDRAWN_STATE;
        hints->flags |= XCB_WM_STATE_HINT;
}

void
xcb_wm_hints_set_none(xcb_wm_hints_t *hints)
{
        hints->flags &= ~XCB_WM_STATE_HINT;
}

void
xcb_wm_hints_set_icon_pixmap(xcb_wm_hints_t *hints, xcb_pixmap_t icon_pixmap)
{
        hints->icon_pixmap = icon_pixmap;
        hints->flags |= XCB_WM_ICON_PIXMAP_HINT;
}

void
xcb_wm_hints_set_icon_mask(xcb_wm_hints_t *hints, xcb_pixmap_t icon_mask)
{
        hints->icon_mask = icon_mask;
        hints->flags |= XCB_WM_ICON_MASK_HINT;
}

void
xcb_wm_hints_set_icon_window(xcb_wm_hints_t *hints, xcb_window_t icon_window)
{
        hints->icon_window = icon_window;
        hints->flags |= XCB_WM_ICON_WINDOW_HINT;
}

void
xcb_wm_hints_set_window_group(xcb_wm_hints_t *hints, xcb_window_t window_group)
{
        hints->window_group = window_group;
        hints->flags |= XCB_WM_WINDOW_GROUP_HINT;
}

void
xcb_wm_hints_set_urgency(xcb_wm_hints_t *hints)
{
        hints->flags |= XCB_WM_X_URGENCY_HINT;
}

void
xcb_set_wm_hints_checked (xcb_connection_t *c,
                          xcb_window_t      window,
                          xcb_wm_hints_t   *hints)
{
	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, WM_HINTS, WM_HINTS, 32, sizeof(*hints) / 4, hints);
}

void
xcb_set_wm_hints (xcb_connection_t *c,
                  xcb_window_t      window,
                  xcb_wm_hints_t   *hints)
{
	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, WM_HINTS, WM_HINTS, 32, sizeof(*hints) / 4, hints);
}

xcb_get_property_cookie_t xcb_get_wm_hints(xcb_connection_t *c,
                                           xcb_window_t window)
{
  return xcb_get_property(c, 0, window, WM_HINTS, WM_HINTS, 0L,
                          XCB_NUM_WM_HINTS_ELEMENTS);
}

xcb_get_property_cookie_t xcb_get_wm_hints_unchecked(xcb_connection_t *c,
                                                     xcb_window_t window)
{
  return xcb_get_property_unchecked(c, 0, window, WM_HINTS, WM_HINTS, 0L,
                                    XCB_NUM_WM_HINTS_ELEMENTS);
}

uint8_t
xcb_get_wm_hints_reply(xcb_connection_t *c,
                       xcb_get_property_cookie_t cookie,
                       xcb_wm_hints_t *hints,
                       xcb_generic_error_t **e)
{
  xcb_get_property_reply_t *reply = xcb_get_property_reply(c, cookie, e);
  if(!reply)
    return 0;

  int length = xcb_get_property_value_length(reply);

  if ((reply->type != WM_HINTS) ||
      (length < (XCB_NUM_WM_HINTS_ELEMENTS - 1)) ||
      (reply->format != 32))
  {
    free(reply);
    return 0;
  }

  memcpy(hints, (xcb_size_hints_t *) xcb_get_property_value(reply),
         length * reply->format >> 3);

  if(length < XCB_NUM_WM_HINTS_ELEMENTS)
    hints->window_group = XCB_NONE;

  return 1;
}

/* WM_PROTOCOLS */

void
xcb_set_wm_protocols_checked (xcb_connection_t *c,
                              xcb_window_t      window,
                              uint32_t          list_len,
                              xcb_atom_t       *list)
{
	intern_atom_fast_cookie_t proto;
	xcb_atom_t WM_PROTOCOLS;

	proto = intern_atom_fast(c, 0, sizeof("WM_PROTOCOLS") - 1, "WM_PROTOCOLS");
	WM_PROTOCOLS = intern_atom_fast_reply(c, proto, 0);

	xcb_change_property_checked(c, XCB_PROP_MODE_REPLACE, window, WM_PROTOCOLS, ATOM, 32, list_len, list);
}

void
xcb_set_wm_protocols (xcb_connection_t *c,
                      xcb_window_t      window,
                      uint32_t          list_len,
                      xcb_atom_t       *list)
{
	intern_atom_fast_cookie_t proto;
	xcb_atom_t WM_PROTOCOLS;

	proto = intern_atom_fast(c, 0, sizeof("WM_PROTOCOLS") - 1, "WM_PROTOCOLS");
	WM_PROTOCOLS = intern_atom_fast_reply(c, proto, 0);

	xcb_change_property(c, XCB_PROP_MODE_REPLACE, window, WM_PROTOCOLS, ATOM, 32, list_len, list);
}

int
xcb_get_wm_protocols (xcb_connection_t *c,
                      xcb_window_t      window,
                      uint32_t         *list_len,
                      xcb_atom_t      **list)
{
        xcb_get_property_cookie_t cookie;
	xcb_get_property_reply_t   *rep;
	xcb_atom_t              property;

	property = intern_atom_fast_reply(c,
                                          intern_atom_fast(c,
                                                           0,
                                                           strlen("WM_PROTOCOLS"),
                                                           "WM_PROTOCOLS"),
                                          NULL);
	cookie = xcb_get_property(c, 0, window,
				property, ATOM, 0, 1000000L);
	rep = xcb_get_property_reply(c, cookie, 0);
	if (!rep)
	        return 0;
	if ((rep->type == ATOM) ||
	    (rep->format == 32))
	{
	        int length;

		length = xcb_get_property_value_length(rep);
		*list_len = length;
		*list = (xcb_atom_t *)malloc(sizeof(xcb_atom_t) * length);
		if (!(*list))
		{
		        free(rep);
			return 0;
		}
		memcpy(*list, xcb_get_property_value(rep), length * rep->format >> 3);
		free(rep);
		return 1;
	}
	free(rep);
	return 0;
}
