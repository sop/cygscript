#ifndef __UTIL__WINPATH_HPP__
#define __UTIL__WINPATH_HPP__

#include <string>
#include "cygpath.hpp"

namespace cygextreg {

class CygPath;

class IWinPath
{
public:
	IWinPath() {
	}
	virtual ~IWinPath() {
	}
};

class WinPathW : public IWinPath
{
	std::wstring _path;

public:
	/**
	 * Constructor.
	 *
	 * @param const std::wstring& path Path in Windows format
	 */
	WinPathW(const std::wstring& path) :
		_path(path) {
	}

	/**
	 * Cast to wstring.
	 *
	 * @return std::wstring Path
	 */
	operator std::wstring() {
		return _path;
	}

	/**
	 * Get path as a wstring.
	 *
	 * @return std::wstring Path
	 */
	std::wstring str() const {
		return _path;
	}

	/**
	 * Convert to Cygwin path.
	 *
	 * @param bool keep_relative Whether to keep path relative
	 * @return CygPath Cygwin path
	 */
	CygPath cygPath(bool keep_relative = false) const;

	/**
	 * Convert to long path.
	 *
	 * @param bool extended Whether to return extended-length path
	 *                      prefixed with \\?\
	 * @return WinPathW Long path
	 */
	WinPathW longPath(bool extended = false) const;

	/**
	 * Get the parent directory path.
	 *
	 * @return WinPathW
	 */
	WinPathW dirname() const;

	/**
	 * Get the filename portion of the path.
	 *
	 * @return WinPathW
	 */
	WinPathW basename() const;

	/**
	 * Get the extension of the filename.
	 * Returns an empty string if there's no extension.
	 *
	 * @return std::wstring
	 */
	std::wstring extension() const;
};

}

#endif
