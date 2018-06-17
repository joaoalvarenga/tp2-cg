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
        ROTATE_POLYGON_PLUS_90,
        ROTATE_POLYGON_MINUS_90,
        GET_AREA_MEASUREMENT,
        GET_ORIENTATION,
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

    enum ORIENTATION {
        CLOCKWISE,
        COUNTERCLOCKWISE
    };
}

#endif //TP2_CG_COMMONS_HPP
