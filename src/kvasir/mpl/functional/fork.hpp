//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "../functional/bind.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template <typename Combiner, typename... Cs>
			struct fork {
				template <typename... Ts>
				using f = typename detail::make_bound<Combiner>::template f<
				        typename detail::make_bound<Cs>::template f<Ts...>...>;
			};
		}
	}
}