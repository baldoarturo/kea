// Copyright (C) 2018-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef ISC_TRANSLATOR_H
#define ISC_TRANSLATOR_H 1

#include <cc/data.h>
#include <yang/sysrepo_error.h>

#include <sysrepo-cpp/Session.hpp>

namespace isc {
namespace yang {

/// @brief Between YANG and JSON translator class for basic values.
class TranslatorBasic {
public:
    using S_Vals = sysrepo::S_Vals;

    /// @brief Constructor.
    ///
    /// @param session Sysrepo session.
    /// @param model Model name (used and shared by derived classes).
    TranslatorBasic(sysrepo::S_Session session, const std::string& model);

    /// @brief Destructor.
    virtual ~TranslatorBasic();

    /// @brief Translate basic value from YANG to JSON.
    ///
    /// @note Please don't use this outside tests.
    ///
    /// @param s_val The value.
    /// @return The Element representing the sysrepo value.
    /// @throw NotImplemented when the value type is not supported.
    static isc::data::ElementPtr value(sysrepo::S_Val s_val);

    /// @brief Get and translate basic value from YANG to JSON.
    ///
    /// @note Should be const as it is read only...
    ///
    /// @param xpath The xpath of the basic value.
    /// @return The Element representing the item at xpath or null
    /// when not found.
    /// @throw SysrepoError when sysrepo raises an error.
    /// @throw NotImplemented when the value type is not supported.
    isc::data::ElementPtr getItem(const std::string& xpath);

    /// @brief Get and translate a list of basic values from YANG to JSON.
    ///
    /// @param xpath The xpath of the list of basic values.
    /// @return The ListElement representing the leaf-list at xpath or
    /// null when not found.
    isc::data::ElementPtr getItems(const std::string& xpath);

    /// @brief Translate basic value from JSON to YANG.
    ///
    /// @note Please don't use this outside tests.
    ///
    /// @param elem The JSON element.
    /// @param type The sysrepo type.
    static sysrepo::S_Val value(isc::data::ConstElementPtr elem,
                                sr_type_t type);

    /// @brief Translate and set basic value from JSON to YANG.
    ///
    /// @param xpath The xpath of the basic value.
    /// @param elem The JSON element.
    /// @param type The sysrepo type.
    void setItem(const std::string& xpath, isc::data::ConstElementPtr elem,
                 sr_type_t type);

    /// @brief Delete basic value from YANG.
    ///
    /// @param xpath The xpath of the basic value.
    void delItem(const std::string& xpath);

    /// @brief Run a function for a node and all its children.
    ///
    /// @tparam functor_t typename of the function to be called
    /// @param xpath the xpath to be travelled
    /// @param f the function to be called
    template <typename functor_t>
    void forAll(std::string const& xpath, functor_t f) {
        libyang::S_Data_Node data_node(session_->get_data(xpath.c_str()));
        if (!data_node) {
            return;
        }

        for (libyang::S_Data_Node& root : data_node->tree_for()) {
            for (libyang::S_Data_Node const& n : root->tree_dfs()) {
                f(n);
            }
        }
    }

    S_Vals getValuesFromItems(std::string const& xpath) {
        try {
            return session_->get_items(xpath.c_str());
        } catch (sysrepo::sysrepo_exception const& exception) {
            isc_throw(SysrepoError, "sysrepo error getting items: " << exception.what());
        }
    }

    template <typename T>
    isc::data::ElementPtr getList(std::string const& xpath,
                                  T& t,
                                  isc::data::ElementPtr (T::*f)(std::string const& xpath)) {
        isc::data::ElementPtr result;
        S_Vals values(getValuesFromItems(xpath));
        if (values) {
            for (size_t i(0); i < values->val_cnt(); ++i) {
                isc::data::ElementPtr x((t.*f)(values->val(i)->xpath()));
                if (x) {
                    if (!result) {
                        result = isc::data::Element::createList();
                    }
                    result->add(x);
                }
            }
        }
        return result;
    }

protected:
    /// @brief The sysrepo session.
    sysrepo::S_Session session_;

    /// @brief The model.
    std::string model_;
};

}  // namespace yang
}  // namespace isc

#endif // ISC_TRANSLATOR_H
