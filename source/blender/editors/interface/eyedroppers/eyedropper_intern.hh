/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup edinterface
 *
 * Share between `interface/eyedropper/` files.
 */

#pragma once

struct ScrArea;
struct bContext;
struct uiBut;
struct wmEvent;
struct wmWindow;

/* `interface_eyedropper.cc` */
void eyedropper_draw_cursor_text_region(const int xy[2], const char *name);
/**
 * Utility to retrieve a button representing a RNA property that is currently under the cursor.
 *
 * This is to be used by any eyedroppers which fetch properties (e.g. #UI_OT_eyedropper_driver).
 * Especially during modal operations (e.g. as with the eyedroppers), context cannot be relied
 * upon to provide this information, as it is not updated until the operator finishes.
 *
 * \return A button under the mouse which relates to some RNA Property, or NULL
 */
uiBut *eyedropper_get_property_button_under_mouse(bContext *C, const wmEvent *event);
void eyedropper_win_area_find(const bContext *C,
                              const int event_xy[2],
                              int r_event_xy[2],
                              wmWindow **r_win,
                              ScrArea **r_area);

/* interface_eyedropper_color.c (expose for color-band picker) */

/**
 * \brief get the color from the screen.
 *
 * Special check for image or nodes where we MAY have HDR pixels which don't display.
 *
 * \param eye: Internal state of the color eyedropper, may be nullptr for other users.
 *
 * \note Exposed by 'eyedropper_intern.hh' for use with color band picking.
 */
struct Eyedropper;
bool eyedropper_color_sample_fl(bContext *C,
                                struct Eyedropper *eye,
                                const int event_xy[2],
                                float r_col[3]);

/* Used for most eye-dropper operators. */
enum {
  EYE_MODAL_CANCEL = 1,
  EYE_MODAL_SAMPLE_CONFIRM,
  EYE_MODAL_SAMPLE_BEGIN,
  EYE_MODAL_SAMPLE_RESET,
};

/* Color-band point sample. */
enum {
  EYE_MODAL_POINT_CANCEL = 1,
  EYE_MODAL_POINT_SAMPLE,
  EYE_MODAL_POINT_CONFIRM,
  EYE_MODAL_POINT_RESET,
  EYE_MODAL_POINT_REMOVE_LAST,
};
