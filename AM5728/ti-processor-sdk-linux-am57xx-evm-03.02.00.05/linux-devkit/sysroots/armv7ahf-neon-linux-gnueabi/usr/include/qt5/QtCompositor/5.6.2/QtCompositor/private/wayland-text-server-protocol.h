/* 
 * Copyright © 2012, 2013 Intel Corporation
 * 
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */

#ifndef TEXT_SERVER_PROTOCOL_H
#define TEXT_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

struct wl_client;
struct wl_resource;

struct wl_seat;
struct wl_surface;
struct wl_text_input;
struct wl_text_input_manager;

extern const struct wl_interface wl_text_input_interface;
extern const struct wl_interface wl_text_input_manager_interface;

#ifndef WL_TEXT_INPUT_CONTENT_HINT_ENUM
#define WL_TEXT_INPUT_CONTENT_HINT_ENUM
/**
 * wl_text_input_content_hint - content hint
 * @WL_TEXT_INPUT_CONTENT_HINT_NONE: no special behaviour
 * @WL_TEXT_INPUT_CONTENT_HINT_DEFAULT: auto completion, correction and
 *	capitalization
 * @WL_TEXT_INPUT_CONTENT_HINT_PASSWORD: hidden and sensitive text
 * @WL_TEXT_INPUT_CONTENT_HINT_AUTO_COMPLETION: suggest word completions
 * @WL_TEXT_INPUT_CONTENT_HINT_AUTO_CORRECTION: suggest word corrections
 * @WL_TEXT_INPUT_CONTENT_HINT_AUTO_CAPITALIZATION: switch to uppercase
 *	letters at the start of a sentence
 * @WL_TEXT_INPUT_CONTENT_HINT_LOWERCASE: prefer lowercase letters
 * @WL_TEXT_INPUT_CONTENT_HINT_UPPERCASE: prefer uppercase letters
 * @WL_TEXT_INPUT_CONTENT_HINT_TITLECASE: prefer casing for titles and
 *	headings (can be language dependent)
 * @WL_TEXT_INPUT_CONTENT_HINT_HIDDEN_TEXT: characters should be hidden
 * @WL_TEXT_INPUT_CONTENT_HINT_SENSITIVE_DATA: typed text should not be
 *	stored
 * @WL_TEXT_INPUT_CONTENT_HINT_LATIN: just latin characters should be
 *	entered
 * @WL_TEXT_INPUT_CONTENT_HINT_MULTILINE: the text input is multiline
 *
 * Content hint is a bitmask to allow to modify the behavior of the text
 * input.
 */
enum wl_text_input_content_hint {
	WL_TEXT_INPUT_CONTENT_HINT_NONE = 0x0,
	WL_TEXT_INPUT_CONTENT_HINT_DEFAULT = 0x7,
	WL_TEXT_INPUT_CONTENT_HINT_PASSWORD = 0xc0,
	WL_TEXT_INPUT_CONTENT_HINT_AUTO_COMPLETION = 0x1,
	WL_TEXT_INPUT_CONTENT_HINT_AUTO_CORRECTION = 0x2,
	WL_TEXT_INPUT_CONTENT_HINT_AUTO_CAPITALIZATION = 0x4,
	WL_TEXT_INPUT_CONTENT_HINT_LOWERCASE = 0x8,
	WL_TEXT_INPUT_CONTENT_HINT_UPPERCASE = 0x10,
	WL_TEXT_INPUT_CONTENT_HINT_TITLECASE = 0x20,
	WL_TEXT_INPUT_CONTENT_HINT_HIDDEN_TEXT = 0x40,
	WL_TEXT_INPUT_CONTENT_HINT_SENSITIVE_DATA = 0x80,
	WL_TEXT_INPUT_CONTENT_HINT_LATIN = 0x100,
	WL_TEXT_INPUT_CONTENT_HINT_MULTILINE = 0x200,
};
#endif /* WL_TEXT_INPUT_CONTENT_HINT_ENUM */

#ifndef WL_TEXT_INPUT_CONTENT_PURPOSE_ENUM
#define WL_TEXT_INPUT_CONTENT_PURPOSE_ENUM
/**
 * wl_text_input_content_purpose - content purpose
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_NORMAL: default input, allowing all
 *	characters
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_ALPHA: allow only alphabetic characters
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_DIGITS: allow only digits
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_NUMBER: input a number (including
 *	decimal separator and sign)
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_PHONE: input a phone number
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_URL: input an URL
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_EMAIL: input an email address
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_NAME: input a name of a person
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_PASSWORD: input a password (combine
 *	with password or sensitive_data hint)
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_DATE: input a date
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_TIME: input a time
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_DATETIME: input a date and time
 * @WL_TEXT_INPUT_CONTENT_PURPOSE_TERMINAL: input for a terminal
 *
 * The content purpose allows to specify the primary purpose of a text
 * input.
 *
 * This allows an input method to show special purpose input panels with
 * extra characters or to disallow some characters.
 */
enum wl_text_input_content_purpose {
	WL_TEXT_INPUT_CONTENT_PURPOSE_NORMAL = 0,
	WL_TEXT_INPUT_CONTENT_PURPOSE_ALPHA = 1,
	WL_TEXT_INPUT_CONTENT_PURPOSE_DIGITS = 2,
	WL_TEXT_INPUT_CONTENT_PURPOSE_NUMBER = 3,
	WL_TEXT_INPUT_CONTENT_PURPOSE_PHONE = 4,
	WL_TEXT_INPUT_CONTENT_PURPOSE_URL = 5,
	WL_TEXT_INPUT_CONTENT_PURPOSE_EMAIL = 6,
	WL_TEXT_INPUT_CONTENT_PURPOSE_NAME = 7,
	WL_TEXT_INPUT_CONTENT_PURPOSE_PASSWORD = 8,
	WL_TEXT_INPUT_CONTENT_PURPOSE_DATE = 9,
	WL_TEXT_INPUT_CONTENT_PURPOSE_TIME = 10,
	WL_TEXT_INPUT_CONTENT_PURPOSE_DATETIME = 11,
	WL_TEXT_INPUT_CONTENT_PURPOSE_TERMINAL = 12,
};
#endif /* WL_TEXT_INPUT_CONTENT_PURPOSE_ENUM */

#ifndef WL_TEXT_INPUT_PREEDIT_STYLE_ENUM
#define WL_TEXT_INPUT_PREEDIT_STYLE_ENUM
enum wl_text_input_preedit_style {
	WL_TEXT_INPUT_PREEDIT_STYLE_DEFAULT = 0,
	WL_TEXT_INPUT_PREEDIT_STYLE_NONE = 1,
	WL_TEXT_INPUT_PREEDIT_STYLE_ACTIVE = 2,
	WL_TEXT_INPUT_PREEDIT_STYLE_INACTIVE = 3,
	WL_TEXT_INPUT_PREEDIT_STYLE_HIGHLIGHT = 4,
	WL_TEXT_INPUT_PREEDIT_STYLE_UNDERLINE = 5,
	WL_TEXT_INPUT_PREEDIT_STYLE_SELECTION = 6,
	WL_TEXT_INPUT_PREEDIT_STYLE_INCORRECT = 7,
};
#endif /* WL_TEXT_INPUT_PREEDIT_STYLE_ENUM */

#ifndef WL_TEXT_INPUT_TEXT_DIRECTION_ENUM
#define WL_TEXT_INPUT_TEXT_DIRECTION_ENUM
enum wl_text_input_text_direction {
	WL_TEXT_INPUT_TEXT_DIRECTION_AUTO = 0,
	WL_TEXT_INPUT_TEXT_DIRECTION_LTR = 1,
	WL_TEXT_INPUT_TEXT_DIRECTION_RTL = 2,
};
#endif /* WL_TEXT_INPUT_TEXT_DIRECTION_ENUM */

/**
 * wl_text_input - text input
 * @activate: request activation
 * @deactivate: request deactivation
 * @show_input_panel: show input panels
 * @hide_input_panel: hide input panels
 * @reset: reset
 * @set_surrounding_text: sets the surrounding text
 * @set_content_type: set content purpose and hint
 * @set_cursor_rectangle: (none)
 * @set_preferred_language: sets preferred language
 * @commit_state: (none)
 * @invoke_action: (none)
 *
 * An object used for text input. Adds support for text input and input
 * methods to applications. A text-input object is created from a
 * wl_text_input_manager and corresponds typically to a text entry in an
 * application. Requests are used to activate/deactivate the text-input
 * object and set state information like surrounding and selected text or
 * the content type. The information about entered text is sent to the
 * text-input object via the pre-edit and commit events. Using this
 * interface removes the need for applications to directly process hardware
 * key events and compose text out of them.
 *
 * Text is generally UTF-8 encoded, indices and lengths are in bytes.
 *
 * Serials are used to synchronize the state between the text input and an
 * input method. New serials are sent by the text input in the commit_state
 * request and are used by the input method to indicate the known text
 * input state in events like preedit_string, commit_string, and keysym.
 * The text input can then ignore events from the input method which are
 * based on an outdated state (for example after a reset).
 */
struct wl_text_input_interface {
	/**
	 * activate - request activation
	 * @seat: (none)
	 * @surface: (none)
	 *
	 * Requests the text-input object to be activated (typically when
	 * the text entry gets focus). The seat argument is a wl_seat which
	 * maintains the focus for this activation. The surface argument is
	 * a wl_surface assigned to the text-input object and tracked for
	 * focus lost. The enter event is emitted on successful activation.
	 */
	void (*activate)(struct wl_client *client,
			 struct wl_resource *resource,
			 struct wl_resource *seat,
			 struct wl_resource *surface);
	/**
	 * deactivate - request deactivation
	 * @seat: (none)
	 *
	 * Requests the text-input object to be deactivated (typically
	 * when the text entry lost focus). The seat argument is a wl_seat
	 * which was used for activation.
	 */
	void (*deactivate)(struct wl_client *client,
			   struct wl_resource *resource,
			   struct wl_resource *seat);
	/**
	 * show_input_panel - show input panels
	 *
	 * Requests input panels (virtual keyboard) to show.
	 */
	void (*show_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * hide_input_panel - hide input panels
	 *
	 * Requests input panels (virtual keyboard) to hide.
	 */
	void (*hide_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * reset - reset
	 *
	 * Should be called by an editor widget when the input state
	 * should be reset, for example after the text was changed outside
	 * of the normal input method flow.
	 */
	void (*reset)(struct wl_client *client,
		      struct wl_resource *resource);
	/**
	 * set_surrounding_text - sets the surrounding text
	 * @text: (none)
	 * @cursor: (none)
	 * @anchor: (none)
	 *
	 * Sets the plain surrounding text around the input position.
	 * Text is UTF-8 encoded. Cursor is the byte offset within the
	 * surrounding text. Anchor is the byte offset of the selection
	 * anchor within the surrounding text. If there is no selected text
	 * anchor is the same as cursor.
	 */
	void (*set_surrounding_text)(struct wl_client *client,
				     struct wl_resource *resource,
				     const char *text,
				     uint32_t cursor,
				     uint32_t anchor);
	/**
	 * set_content_type - set content purpose and hint
	 * @hint: (none)
	 * @purpose: (none)
	 *
	 * Sets the content purpose and content hint. While the purpose
	 * is the basic purpose of an input field, the hint flags allow to
	 * modify some of the behavior.
	 *
	 * When no content type is explicitly set, a normal content purpose
	 * with default hints (auto completion, auto correction, auto
	 * capitalization) should be assumed.
	 */
	void (*set_content_type)(struct wl_client *client,
				 struct wl_resource *resource,
				 uint32_t hint,
				 uint32_t purpose);
	/**
	 * set_cursor_rectangle - (none)
	 * @x: (none)
	 * @y: (none)
	 * @width: (none)
	 * @height: (none)
	 */
	void (*set_cursor_rectangle)(struct wl_client *client,
				     struct wl_resource *resource,
				     int32_t x,
				     int32_t y,
				     int32_t width,
				     int32_t height);
	/**
	 * set_preferred_language - sets preferred language
	 * @language: (none)
	 *
	 * Sets a specific language. This allows for example a virtual
	 * keyboard to show a language specific layout. The "language"
	 * argument is a RFC-3066 format language tag.
	 *
	 * It could be used for example in a word processor to indicate
	 * language of currently edited document or in an instant message
	 * application which tracks languages of contacts.
	 */
	void (*set_preferred_language)(struct wl_client *client,
				       struct wl_resource *resource,
				       const char *language);
	/**
	 * commit_state - (none)
	 * @serial: used to identify the known state
	 */
	void (*commit_state)(struct wl_client *client,
			     struct wl_resource *resource,
			     uint32_t serial);
	/**
	 * invoke_action - (none)
	 * @button: (none)
	 * @index: (none)
	 */
	void (*invoke_action)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t button,
			      uint32_t index);
};

#define WL_TEXT_INPUT_ENTER	0
#define WL_TEXT_INPUT_LEAVE	1
#define WL_TEXT_INPUT_MODIFIERS_MAP	2
#define WL_TEXT_INPUT_INPUT_PANEL_STATE	3
#define WL_TEXT_INPUT_PREEDIT_STRING	4
#define WL_TEXT_INPUT_PREEDIT_STYLING	5
#define WL_TEXT_INPUT_PREEDIT_CURSOR	6
#define WL_TEXT_INPUT_COMMIT_STRING	7
#define WL_TEXT_INPUT_CURSOR_POSITION	8
#define WL_TEXT_INPUT_DELETE_SURROUNDING_TEXT	9
#define WL_TEXT_INPUT_KEYSYM	10
#define WL_TEXT_INPUT_LANGUAGE	11
#define WL_TEXT_INPUT_TEXT_DIRECTION	12

#define WL_TEXT_INPUT_ENTER_SINCE_VERSION	1
#define WL_TEXT_INPUT_LEAVE_SINCE_VERSION	1
#define WL_TEXT_INPUT_MODIFIERS_MAP_SINCE_VERSION	1
#define WL_TEXT_INPUT_INPUT_PANEL_STATE_SINCE_VERSION	1
#define WL_TEXT_INPUT_PREEDIT_STRING_SINCE_VERSION	1
#define WL_TEXT_INPUT_PREEDIT_STYLING_SINCE_VERSION	1
#define WL_TEXT_INPUT_PREEDIT_CURSOR_SINCE_VERSION	1
#define WL_TEXT_INPUT_COMMIT_STRING_SINCE_VERSION	1
#define WL_TEXT_INPUT_CURSOR_POSITION_SINCE_VERSION	1
#define WL_TEXT_INPUT_DELETE_SURROUNDING_TEXT_SINCE_VERSION	1
#define WL_TEXT_INPUT_KEYSYM_SINCE_VERSION	1
#define WL_TEXT_INPUT_LANGUAGE_SINCE_VERSION	1
#define WL_TEXT_INPUT_TEXT_DIRECTION_SINCE_VERSION	1

static inline void
wl_text_input_send_enter(struct wl_resource *resource_, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_ENTER, surface);
}

static inline void
wl_text_input_send_leave(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_LEAVE);
}

static inline void
wl_text_input_send_modifiers_map(struct wl_resource *resource_, struct wl_array *map)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_MODIFIERS_MAP, map);
}

static inline void
wl_text_input_send_input_panel_state(struct wl_resource *resource_, uint32_t state)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_INPUT_PANEL_STATE, state);
}

static inline void
wl_text_input_send_preedit_string(struct wl_resource *resource_, uint32_t serial, const char *text, const char *commit)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_PREEDIT_STRING, serial, text, commit);
}

static inline void
wl_text_input_send_preedit_styling(struct wl_resource *resource_, uint32_t index, uint32_t length, uint32_t style)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_PREEDIT_STYLING, index, length, style);
}

static inline void
wl_text_input_send_preedit_cursor(struct wl_resource *resource_, int32_t index)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_PREEDIT_CURSOR, index);
}

static inline void
wl_text_input_send_commit_string(struct wl_resource *resource_, uint32_t serial, const char *text)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_COMMIT_STRING, serial, text);
}

static inline void
wl_text_input_send_cursor_position(struct wl_resource *resource_, int32_t index, int32_t anchor)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_CURSOR_POSITION, index, anchor);
}

static inline void
wl_text_input_send_delete_surrounding_text(struct wl_resource *resource_, int32_t index, uint32_t length)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_DELETE_SURROUNDING_TEXT, index, length);
}

static inline void
wl_text_input_send_keysym(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t sym, uint32_t state, uint32_t modifiers)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_KEYSYM, serial, time, sym, state, modifiers);
}

static inline void
wl_text_input_send_language(struct wl_resource *resource_, uint32_t serial, const char *language)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_LANGUAGE, serial, language);
}

static inline void
wl_text_input_send_text_direction(struct wl_resource *resource_, uint32_t serial, uint32_t direction)
{
	wl_resource_post_event(resource_, WL_TEXT_INPUT_TEXT_DIRECTION, serial, direction);
}

/**
 * wl_text_input_manager - text input manager
 * @create_text_input: create text input
 *
 * A factory for text-input objects. This object is a global singleton.
 */
struct wl_text_input_manager_interface {
	/**
	 * create_text_input - create text input
	 * @id: (none)
	 *
	 * Creates a new text-input object.
	 */
	void (*create_text_input)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t id);
};


#ifdef  __cplusplus
}
#endif

#endif
