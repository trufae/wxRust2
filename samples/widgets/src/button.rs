use std::cell::RefCell;
use std::os::raw::{c_int, c_long};
use std::rc::Rc;
use wx::methods::*;

// control ids
#[derive(Clone, Copy)]
enum ButtonPage {
    Reset = wx::ID_HIGHEST as isize,
    ChangeLabel,
    // ChangeNote, // for CommandLinkButton
    Button,
}
impl ButtonPage {
    fn from(v: c_int) -> Option<Self> {
        use ButtonPage::*;
        for e in [
            Reset,
            ChangeLabel,
            // ChangeNote,
            Button,
        ] {
            if v == e.into() {
                return Some(e);
            }
        }
        return None;
    }
}
impl From<ButtonPage> for c_int {
    fn from(w: ButtonPage) -> Self {
        w as c_int
    }
}

const BUTTON_IMAGE_POS_LEFT: c_int = 0;
const BUTTON_IMAGE_POS_RIGHT: c_int = 1;
const BUTTON_IMAGE_POS_TOP: c_int = 2;
const BUTTON_IMAGE_POS_BOTTOM: c_int = 3;

const BUTTON_HALIGN_LEFT: c_int = 0;
const BUTTON_HALIGN_CENTRE: c_int = 1;
const BUTTON_HALIGN_RIGHT: c_int = 2;

const BUTTON_VALIGN_TOP: c_int = 0;
const BUTTON_VALIGN_CENTRE: c_int = 1;
const BUTTON_VALIGN_BOTTOM: c_int = 2;

#[derive(Clone)]
pub struct ConfigUI {
    // the check/radio boxes for styles
    chk_bitmap_only: wx::CheckBox,
    chk_text_and_bitmap: wx::CheckBox,
    chk_fit: wx::CheckBox,
    chk_auth_needed: wx::CheckBox,
    chk_default: wx::CheckBox,
    chk_use_bitmap_class: wx::CheckBox,
    chk_disable: wx::CheckBox,
    radio_image_pos: wx::RadioBox,
    radio_halign: wx::RadioBox,
    radio_valign: wx::RadioBox,
    sizer_button: wx::BoxSizer,
    // the text entries for command parameters
    text_label: wx::TextCtrl,
}
impl ConfigUI {
    fn reset(&self) {
        self.chk_bitmap_only.set_value(false);
        self.chk_fit.set_value(false);
        self.chk_auth_needed.set_value(false);
        self.chk_text_and_bitmap.set_value(false);
        self.chk_default.set_value(false);
        self.chk_use_bitmap_class.set_value(true);
        self.chk_disable.set_value(false);

        // self.chk_use_pressed.set_value(true);
        // self.chk_use_focused.set_value(true);
        // self.chk_use_current.set_value(true);
        // self.chk_use_disabled.set_value(true);

        self.radio_image_pos.set_selection(BUTTON_IMAGE_POS_LEFT);
        self.radio_halign.set_selection(BUTTON_HALIGN_CENTRE);
        self.radio_valign.set_selection(BUTTON_VALIGN_CENTRE);
    }
}

#[derive(Clone)]
pub struct ButtonWidgetsPage {
    pub base: wx::Panel,
    config_ui: RefCell<Option<ConfigUI>>,
    // the button itself and the sizer it is in
    button: Rc<RefCell<Option<wx::Button>>>,
}
impl ButtonWidgetsPage {
    pub fn new<P: WindowMethods>(book: &P) -> Self {
        let panel = wx::Panel::builder(Some(book))
            .style(wx::CLIP_CHILDREN | wx::TAB_TRAVERSAL)
            .build();
        ButtonWidgetsPage {
            base: panel,
            config_ui: RefCell::new(None),
            button: Rc::new(RefCell::new(None)),
        }
    }

    pub fn create_content(&self) {
        let sizer_top = wx::BoxSizer::new(wx::HORIZONTAL);

        // left pane
        let s_box = wx::StaticBox::builder(Some(&self.base))
            .label("&Set style")
            .build();

        let sizer_left = wx::StaticBoxSizer::new_with_staticbox(Some(&s_box), wx::VERTICAL);

        let chk_bitmap_only =
            self.create_check_box_and_add_to_sizer(&sizer_left, "&Bitmap only", wx::ID_ANY);
        let chk_text_and_bitmap =
            self.create_check_box_and_add_to_sizer(&sizer_left, "Text &and bitmap", wx::ID_ANY);
        let chk_fit =
            self.create_check_box_and_add_to_sizer(&sizer_left, "&Fit exactly", wx::ID_ANY);
        let chk_auth_needed =
            self.create_check_box_and_add_to_sizer(&sizer_left, "Require a&uth", wx::ID_ANY);
        let chk_default =
            self.create_check_box_and_add_to_sizer(&sizer_left, "&Default", wx::ID_ANY);

        let chk_use_bitmap_class =
            self.create_check_box_and_add_to_sizer(&sizer_left, "Use wxBitmapButton", wx::ID_ANY);
        chk_use_bitmap_class.set_value(true);

        let chk_disable =
            self.create_check_box_and_add_to_sizer(&sizer_left, "Disable", wx::ID_ANY);

        sizer_left.add_spacer(5);

        let sizer_use_labels = wx::StaticBoxSizer::new_with_int(
            wx::VERTICAL,
            Some(&self.base),
            "&Use the following bitmaps in addition to the normal one?",
        );
        let chk_use_pressed = self.create_check_box_and_add_to_sizer(
            &sizer_use_labels,
            "&Pressed (small help icon)",
            wx::ID_ANY,
        );
        let chk_use_focused = self.create_check_box_and_add_to_sizer(
            &sizer_use_labels,
            "&Focused (small error icon)",
            wx::ID_ANY,
        );
        let chk_use_current = self.create_check_box_and_add_to_sizer(
            &sizer_use_labels,
            "&Current (small warning icon)",
            wx::ID_ANY,
        );
        let chk_use_disabled = self.create_check_box_and_add_to_sizer(
            &sizer_use_labels,
            "&Disabled (broken image icon)",
            wx::ID_ANY,
        );
        sizer_left.add_sizer_sizerflags(
            Some(&sizer_use_labels),
            wx::SizerFlags::new(0).expand().border(wx::ALL),
        );

        sizer_left.add_spacer(10);

        let dirs = wx::ArrayString::new();
        dirs.add("left");
        dirs.add("right");
        dirs.add("top");
        dirs.add("bottom");
        let radio_image_pos = wx::RadioBox::builder(Some(&self.base))
            .label("Image &position")
            .choices(dirs)
            .build();
        sizer_left.add_window_sizerflags(
            Some(&radio_image_pos),
            wx::SizerFlags::new(0).expand().border(wx::ALL),
        );
        sizer_left.add_spacer(15);

        let halign = wx::ArrayString::new();
        halign.add("left");
        halign.add("centre");
        halign.add("right");
        let radio_halign = wx::RadioBox::builder(Some(&self.base))
            .label("&Horz alignment")
            .choices(halign)
            .build();

        let valign = wx::ArrayString::new();
        valign.add("top");
        valign.add("centre");
        valign.add("bottom");
        let radio_valign = wx::RadioBox::builder(Some(&self.base))
            .label("&Vert alignment")
            .choices(valign)
            .build();

        sizer_left.add_window_sizerflags(
            Some(&radio_halign),
            wx::SizerFlags::new(0).expand().border(wx::ALL),
        );
        sizer_left.add_window_sizerflags(
            Some(&radio_valign),
            wx::SizerFlags::new(0).expand().border(wx::ALL),
        );

        sizer_left.add_spacer(5);

        let btn = wx::Button::builder(Some(&self.base))
            .id(ButtonPage::Reset.into())
            .label("&Reset")
            .build();
        sizer_left.add_window_int(
            Some(&btn),
            0,
            wx::ALIGN_CENTRE_HORIZONTAL | wx::ALL,
            15,
            wx::Object::none(),
        );

        // middle pane
        let s_box2 = wx::StaticBox::builder(Some(&self.base))
            .label("&Operations")
            .build();
        let sizer_middle = wx::StaticBoxSizer::new_with_staticbox(Some(&s_box2), wx::VERTICAL);

        let (sizer_row, text_label) = self.create_sizer_with_text_and_button(
            ButtonPage::ChangeLabel.into(),
            "Change label",
            wx::ID_ANY,
        );
        text_label.set_value("&Press me!");
        sizer_middle.add_sizer_sizerflags(
            Some(&sizer_row),
            wx::SizerFlags::new(0).expand().border(wx::ALL),
        );

        // right pane
        let sizer_button = wx::BoxSizer::new(wx::HORIZONTAL);
        sizer_button.set_min_size_int(150, 0);

        // the 3 panes panes compose the window
        sizer_top.add_sizer_sizerflags(
            Some(&sizer_left),
            wx::SizerFlags::new(0)
                .expand()
                .double_border(wx::ALL & !wx::LEFT),
        );
        sizer_top.add_sizer_sizerflags(
            Some(&sizer_middle),
            wx::SizerFlags::new(1).expand().double_border(wx::ALL),
        );
        sizer_top.add_sizer_sizerflags(
            Some(&sizer_button),
            wx::SizerFlags::new(1)
                .expand()
                .double_border(wx::ALL & !wx::RIGHT),
        );
        *self.config_ui.borrow_mut() = Some(ConfigUI {
            chk_bitmap_only,
            chk_text_and_bitmap,
            chk_fit,
            chk_auth_needed,
            chk_default,
            chk_use_bitmap_class,
            chk_disable,
            radio_image_pos,
            radio_halign,
            radio_valign,
            sizer_button,
            text_label,
        });

        // do create the main control
        self.reset();
        self.create_button();

        self.base.set_sizer(Some(&sizer_top), true);
    }

    fn recreate_widget(&self) {
        self.create_button();
    }

    fn reset(&self) {
        if let Some(config_ui) = self.config_ui.borrow().as_ref() {
            config_ui.reset();
        }
    }

    fn create_button(&self) {
        if let Some(config_ui) = self.config_ui.borrow().as_ref() {
            let mut label = "".to_string();
            if let Some(button) = self.button.borrow().as_ref() {
                label = button.get_label();

                // TODO: remove (and delete) all buttons
                let count = config_ui.sizer_button.get_children().get_count();
                for _ in 0..count {
                    config_ui.sizer_button.remove_int(0);
                }
                button.destroy();
            }

            if label.is_empty() {
                label = config_ui.text_label.get_value();
            }

            let mut flags = wx::BORDER_DEFAULT;
            flags |= match config_ui.radio_halign.get_selection() {
                BUTTON_HALIGN_LEFT => wx::BU_LEFT,
                BUTTON_HALIGN_RIGHT => wx::BU_RIGHT,
                _ => 0,
            } as c_long;

            flags |= match config_ui.radio_valign.get_selection() {
                BUTTON_VALIGN_TOP => wx::BU_TOP,
                BUTTON_VALIGN_BOTTOM => wx::BU_BOTTOM,
                // centre vertical alignment is the default (no style)
                _ => 0,
            } as c_long;

            if config_ui.chk_fit.get_value() {
                flags |= wx::BU_EXACTFIT as c_long;
            }

            let mut shows_bitmap = false;
            let new_button = if config_ui.chk_bitmap_only.get_value() {
                shows_bitmap = true;

                let bbtn: wx::Button;
                // TODO: Support downcasting from BitmapButton into Button
                //
                // let bbtn: wx::BitmapButton;
                // if config_ui.chk_use_bitmap_class.get_value() {
                //     // TODO: create bitmap
                //     let icon_bitmap = wx::Bitmap::new();
                //     icon_bitmap.copy_from_icon(&wx::ArtProvider::get_icon(
                //         // wxRust TODO: generate these constants...
                //         "wxART_INFORMATION",
                //         "wxART_BUTTON_C",
                //         &wx::Size::default(),
                //     ));
                //     bbtn = wx::BitmapButton::builder(Some(&self.base))
                //         .style(flags)
                //         .build(&icon_bitmap);
                // } else {
                // TODO: create bitmap
                bbtn = wx::Button::builder(Some(&self.base))
                    .id(ButtonPage::Button.into())
                    .build();
                let icon_bitmap = wx::Bitmap::new();
                icon_bitmap.copy_from_icon(&wx::ArtProvider::get_icon(
                    // wxRust TODO: generate these constants...
                    "wxART_INFORMATION",
                    "wxART_BUTTON_C",
                    &wx::Size::default(),
                ));
                bbtn.set_bitmap_label(&icon_bitmap);
                // }

                bbtn
            } else {
                wx::Button::builder(Some(&self.base))
                    .id(ButtonPage::Button.into())
                    .label(&label)
                    .style(flags)
                    .build()
            };

            let mut shows_bitmap = false;
            if !shows_bitmap && config_ui.chk_text_and_bitmap.get_value() {
                shows_bitmap = true;

                let positions = [wx::LEFT, wx::RIGHT, wx::TOP, wx::BOTTOM];
                let icon_bitmap = wx::Bitmap::new();
                icon_bitmap.copy_from_icon(&wx::ArtProvider::get_icon(
                    // wxRust TODO: generate these constants...
                    "wxART_INFORMATION",
                    "wxART_BUTTON_C",
                    &wx::Size::default(),
                ));
                new_button.set_bitmap(
                    &icon_bitmap,
                    positions[config_ui.radio_image_pos.get_selection() as usize],
                );
            }

            config_ui.chk_use_bitmap_class.enable(shows_bitmap);

            if config_ui.chk_auth_needed.get_value() {
                new_button.set_auth_needed(true);
            }

            if config_ui.chk_default.get_value() {
                new_button.set_default();
            }

            new_button.enable(!config_ui.chk_disable.is_checked());

            let sizer_button = &config_ui.sizer_button;
            sizer_button.add_stretch_spacer(1);
            sizer_button.add_window_sizerflags(
                Some(&new_button),
                wx::SizerFlags::new(0).centre().border(wx::ALL),
            );
            sizer_button.add_stretch_spacer(1);

            sizer_button.layout();

            *self.button.borrow_mut() = Some(new_button);
        }
    }

    // Utility methods from (and to be placed to) the base WidgetPage class

    fn create_sizer_with_text<C: ControlMethods>(
        &self,
        control: &C,
        id: c_int,
    ) -> (wx::BoxSizer, wx::TextCtrl) {
        let sizer_row = wx::BoxSizer::new(wx::HORIZONTAL);
        let text = wx::TextCtrl::builder(Some(&self.base))
            .id(id)
            .style(wx::TE_PROCESS_ENTER.into())
            .build();

        sizer_row.add_window_int(
            Some(control),
            0,
            wx::RIGHT | wx::ALIGN_CENTRE_VERTICAL,
            5,
            wx::Object::none(),
        );
        sizer_row.add_window_int(
            Some(&text),
            1,
            wx::LEFT | wx::ALIGN_CENTRE_VERTICAL,
            5,
            wx::Object::none(),
        );

        (sizer_row, text)
    }

    fn create_sizer_with_text_and_button(
        &self,
        id_btn: c_int,
        label: &str,
        id: c_int,
    ) -> (wx::BoxSizer, wx::TextCtrl) {
        let btn = wx::Button::builder(Some(&self.base))
            .id(id_btn)
            .label(label)
            .build();
        self.create_sizer_with_text(&btn, id)
    }

    fn create_check_box_and_add_to_sizer<S: SizerMethods>(
        &self,
        sizer: &S,
        label: &str,
        id: c_int,
    ) -> wx::CheckBox {
        let checkbox = wx::CheckBox::builder(Some(&self.base))
            .id(id)
            .label(label)
            .build();
        sizer.add_window_sizerflags(Some(&checkbox), wx::SizerFlags::new(0).double_horz_border());
        sizer.add_spacer(2);

        return checkbox;
    }

    pub fn handle_button(&self, event: &wx::CommandEvent) {
        println!("event={}", event.get_id());
        if let Some(m) = ButtonPage::from(event.get_id()) {
            match m {
                ButtonPage::Reset => self.on_button_reset(),
                ButtonPage::ChangeLabel => self.on_button_change_label(),
                _ => (),
            };
        }
    }
    fn on_button_reset(&self) {
        self.reset();
        // TODO: make mut self callable here, or
        // make create_button() not to require mut self.
        self.create_button();
    }

    pub fn handle_checkbox(&self, _: &wx::CommandEvent) {
        self.on_check_or_radio_box();
    }
    pub fn handle_radiobox(&self, _: &wx::CommandEvent) {
        self.on_check_or_radio_box();
    }
    fn on_check_or_radio_box(&self) {
        self.create_button();
        self.base.layout(); // make sure the text field for changing note displays correctly.
    }

    fn on_button_change_label(&self) {
        if let Some(config_ui) = self.config_ui.borrow().as_ref() {
            let label_text = config_ui.text_label.get_value();
            println!("{}", label_text);

            self.button
                .borrow()
                .as_ref()
                .unwrap()
                .set_label(&label_text);

            config_ui.sizer_button.layout();
        }
    }
}
