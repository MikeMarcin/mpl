//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "../functional/fork.hpp"
#include "../types/list.hpp"
namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template <typename C, typename L, typename... Ts>
				struct call_impl;
				template <typename C, template <typename...> class Seq, typename... Ls>
				struct call_impl<C, Seq<Ls...>> {
					using type = KVASIR_D_CALL(C, Ls)<Ls...>;
				};
				// forking version of call expects a "combining" continuation as its first arguement
				// and a variadic pack of continuations which are executed in paralell
				template <typename R, typename... C, template <typename...> class Seq,
				          typename... Ls>
				struct call_impl<fork<R, C...>, Seq<Ls...>> {
					using type = typename detail::make_bound<R>::template f<
					        typename detail::make_bound<C>::template f<Ls...>...>;
				};
			}
			template <typename C, typename L, typename... Ls>
			using call = typename detail::call_impl<C, L, Ls...>::type;
		}
	}
}