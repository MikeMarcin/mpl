//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_if.hpp"
#include "../sequence/size.hpp"
#include "../functional/compose.hpp"
#include "../utility/invert.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			/// generic implementation for any list type
			template <template <typename...> class Cond, typename List>
			struct contains_impl {
				template <typename T>
				using inverse_cond = invert<Cond<T>>;

				constexpr operator bool() const {
					return size_impl<typename remove_if_impl<inverse_cond, List>::f>{} > 0;
				}
			};
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using contains = impl::contains_impl<Cond, List>;
	}
}
