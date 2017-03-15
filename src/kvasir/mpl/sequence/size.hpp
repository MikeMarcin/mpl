//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/int.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			struct size {
				template <typename... Ts>
				struct f {
					constexpr static auto value = sizeof...(Ts);
				};
			};

			/// offset provides the difference between the origional length of a list
			///(provided as the input parameter) and the pack supplied to f
			template <typename T>
			struct offset {
				template <typename... Ts>
				struct f {
					constexpr static auto value = (T::value - sizeof...(Ts));
				};
			};
		}
		namespace impl {
			template <typename List>
			struct size_impl;

			/// kvasir::mpl::list implementation
			template <typename... Ts>
			struct size_impl<mpl::list<Ts...>> {
				static constexpr auto value = sizeof...(Ts);
			};
		}

		/// get the size of a list, the returned type is convertible to some unspecified int type
		template <typename List>
		using size = typename c::size::template f<List>;
	}
}
