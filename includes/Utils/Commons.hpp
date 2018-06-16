//
// Created by joao on 15/06/18.
//

#ifndef TP2_CG_COMMONS_HPP
#define TP2_CG_COMMONS_HPP

namespace commons {
    enum MENU_OPTIONS {
        CREATE_POLYGON,
        SELECT_POLYGON,
        TRANSLATE_POLYGON,
        ROTATE_POLYGON,
        AREA_MEASURE,
        SET_ORIENTATION,
        DELETE,
        CLEAR,
        QUIT
    };

    enum APPLICATION_STATUS {
        NONE,
        CREATE,
        SELECT,
        TRANSLATE,
        ROTATE
    };
}

#endif //TP2_CG_COMMONS_HPP
